

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
	FXMLLoader loader = new FXMLLoader();
        Parent root = loader.load(getClass().getResource("gui.fxml"));
        primaryStage.setTitle("Hello World");
        Scene scene = new Scene(root, 900, 900);
        scene.getStylesheets().add(getClass().getResource("main.css").toExternalForm());
        primaryStage.setScene(scene);

        primaryStage.show();
    }


    public static void main(String[] args) {
        Controller.setTcp(args[0], Integer.parseInt(args[1]));
        launch(args);
    }
}
