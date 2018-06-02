

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.geometry.HPos;
import javafx.geometry.VPos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.ImageView;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.RowConstraints;

import java.awt.*;
import java.io.IOException;
import java.util.*;
import java.util.List;

import static java.lang.System.exit;

public class Controller {
    private int width;
    private int height;
    private Queue<ImageView> taxiImages;
    private Map<Integer, ImageView> taxiOnGrid;
    private static TCPClient client;
    private int timeCounter = 0;

    @FXML
    Button btnSend;

    @FXML
    Button btnAdd;

    @FXML
    Label timer;

    @FXML
    Label error;

    @FXML
    TextField insertCommand;

    @FXML
    TextField newDriver;

    @FXML
    GridPane grid;


    public static void setTcp(String IP, int port){
        try {
            client = new TCPClient(IP, port);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @FXML
    void initialize() {
        taxiOnGrid = new HashMap<Integer, ImageView>();
        taxiImages = new LinkedList<ImageView>();
        for (int i = 1; i < 6; i++) {
            ImageView imageView = new ImageView("taxi" + Integer.toString(i) + ".jpg");
            taxiImages.add(imageView);
        }


        timer.setText("Time: " + Integer.toString(timeCounter));
        error.setText("");
        String gridArgs = null;

        try {
            gridArgs = client.receiveData();
        } catch (IOException e) {
            e.printStackTrace();
        }

        String splitArgs[] = gridArgs.split(" ");
        width = Integer.parseInt(splitArgs[0]);
        height = Integer.parseInt(splitArgs[1]);
        int numOfObstacles = Integer.parseInt(splitArgs[2]);

        double percentWidth = 100.0 / width;
        double percentHeight = 100.0 / height;

        //Remove all the rows and columns from the grid so that it's 0x0.
        grid.getColumnConstraints().removeAll(grid.getColumnConstraints());
        grid.getRowConstraints().removeAll(grid.getRowConstraints());

        //Set the grid's number of rows and columns.
        for (int i = 0; i < width; i++) {
            ColumnConstraints colConst = new ColumnConstraints();
            colConst.setPercentWidth(percentWidth);
            grid.getColumnConstraints().add(colConst);
        }
        for (int i = 0; i < height; i++) {
            RowConstraints rowConst = new RowConstraints();
            rowConst.setPercentHeight(percentHeight);
            grid.getRowConstraints().add(rowConst);
        }

        if (numOfObstacles > 0) {
            String obstaclesString = splitArgs[3];
            String obstacles[] = obstaclesString.split("-");
            //Read the obstacles and place the obstacles images on the grid.
            for (int i = 0; i < numOfObstacles; i++) {
                String point[] = obstacles[i].split(",");
                addObstacle(Integer.parseInt(point[0]), Integer.parseInt(point[1]));
            }
        }
    }


    private void addObstacle(int x, int y){
        ImageView imageView = new ImageView("block2.jpg");
        imageView.fitWidthProperty().bind(grid.widthProperty().divide(width));
        imageView.fitHeightProperty().bind(grid.heightProperty().divide(height));
        grid.add(imageView, x, height - 1 - y);

        //Make sure the images are centered within each cell.
        GridPane.setHalignment(imageView, HPos.CENTER);
        GridPane.setValignment(imageView, VPos.CENTER);
    }



    @FXML
    public void run() {
        //Setting an action for the Submit button
        btnSend.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent e) {
                if ((insertCommand.getText() != null && !insertCommand.getText().isEmpty())) {
                    String command = insertCommand.getText();
                    try {
                        client.sendData(command);
                        String msg = client.receiveData();
                        if (command.equals("7")) {
                            client.close();
                            exit(0);
                        } else if(command.equals("9")) {
                            timeCounter += 1;
                            timer.setText("Time: " + Integer.toString(timeCounter));
                            if (!msg.contains("empty")) {
                                error.setText(msg);
                                msg = msg.split("-")[1];
                                String[] parts = msg.split(" ");//new driver
                                int idDriver;
                                int xDriver;
                                int yDriver;
                                for (String str : parts) {//format:idDriver1,pointX,pointY idDriver2,pointX,pointY ...
                                        String[] partsArgsDrivers = str.split(",");
                                        idDriver = Integer.getInteger(partsArgsDrivers[0]);//id driver;
                                        xDriver = Integer.getInteger(partsArgsDrivers[1]);//get x
                                        yDriver = Integer.getInteger(partsArgsDrivers[2]);//get y

                                        ImageView imageView = taxiOnGrid.get(idDriver);
                                        imageView.fitWidthProperty().bind(grid.widthProperty().divide(width));
                                        imageView.fitHeightProperty().bind(grid.heightProperty().divide(height));
                                        grid.add(imageView, xDriver, height - 1 - yDriver);
                                        //Make sure the images are centered within each cell.
                                        GridPane.setHalignment(imageView, HPos.CENTER);
                                        GridPane.setValignment(imageView, VPos.CENTER);
                                }
                            }
                        } else if (msg.contains("error")) {
                            error.setText("invalid input");
                        }

                    } catch (IOException e1) {
                        e1.printStackTrace();
                        insertCommand.clear();
                    }
                    insertCommand.clear();
                } else {
                    error.setText("You have not left a command.");
                }
            }
        });

        btnAdd.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent e) {
                if ((newDriver.getText() != null && !newDriver.getText().isEmpty())) {
                    String driverArgs = newDriver.getText();
                    String idDriver  = driverArgs.split(",")[0];
                    int id = Integer.parseInt(idDriver);
                    String runtimeArgs[] = new String[4];
                    taxiOnGrid.put(id, taxiImages.poll());


                    //Create the runtime arguments
                    runtimeArgs[0] = "./client.out";
                    runtimeArgs[1] = client.getIP();
                    runtimeArgs[2] = Integer.toString(client.getPort());
                    runtimeArgs[3] = driverArgs;
                    //Run a client with the runtime arguments
                    try {
                        Runtime.getRuntime().exec(runtimeArgs);
                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }

                    ImageView imageView = taxiOnGrid.get(id);
                    imageView.fitWidthProperty().bind(grid.widthProperty().divide(width));
                    imageView.fitHeightProperty().bind(grid.heightProperty().divide(height));
                    grid.add(imageView, 0, height - 1);
                    //Make sure the images are centered within each cell.
                    GridPane.setHalignment(imageView, HPos.CENTER);
                    GridPane.setValignment(imageView, VPos.CENTER);
                    newDriver.clear();
                } else {
                    error.setText("You have not left a comment.");
                }
            }
        });
    }

}


