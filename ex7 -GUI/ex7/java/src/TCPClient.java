

/**
 * Project: ex7
 * Created by simon on 08/03/2017.
 */

import java.io.*;
import java.net.*;

class TCPClient
{
    private String IP;
    private int port;
    private Socket clientSocket;
    private PrintWriter outToServer;
    private InputStreamReader inFromServer;

    public TCPClient(String IP, int port) throws IOException {
        this.IP = IP;
        this.port = port;
        clientSocket = new Socket(IP, port);
        outToServer = new PrintWriter(clientSocket.getOutputStream(), true);
        inFromServer =  new InputStreamReader(clientSocket.getInputStream());;
    }

    public Socket getClientSocket() {
        return clientSocket;
    }

    public String getIP(){
        return this.IP;
    }

    public int getPort() {
        return port;
    }

    public void sendData(String s) throws IOException {
        outToServer.println(s);
    }

    public String receiveData() throws IOException {
        char[] buffer = new char[8192];
        int bytes = inFromServer.read(buffer, 0, 8192);
        if (bytes > 0) {
            return new String(buffer, 0, bytes);
        } else {
            throw new IOException("error reading");
        }
    }

    public void close() throws IOException {
        clientSocket.close();
    }

}
