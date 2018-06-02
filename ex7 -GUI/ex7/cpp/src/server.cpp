
#include "core/Matrix.h"
#include "TaxiCenter.h"
#include "Menu.h"
#include <iostream>
#include <boost/algorithm/string.hpp>

vector<NodeMatrix*>* deleteObstacles(vector<NodeMatrix *> *obstacles) {
    for (int i = 0; i < obstacles->size(); ++i) {
        delete (*obstacles)[i];
    }
    delete obstacles;
    return NULL;
}

vector<NodeMatrix*>* getObstacles(InputParser *inputParser, long width, long height, string* guiStr) {
    vector<NodeMatrix *> *obstacles = new vector<NodeMatrix *>();
    ;
    string input;
    long numOfObstacles;
    long x;
    long y;
    //num of obstacles
    getline(cin, input);
    trim(input);
    if (!inputParser->checkInput(regex("\\d+"), input)) {
        return NULL;
    }
    *guiStr += " " + input + " ";

    numOfObstacles = atoi(input.c_str());
    while (numOfObstacles > 0) {
        input.clear();
        getline(cin, input);
        trim(input);
        if (inputParser->checkInput(regex("\\d+,\\d+"), input)) {
            vector<string> temp;
            boost::split(temp, input, boost::is_any_of(","));
            x = atol(temp[0].c_str());
            y = atol(temp[1].c_str());
            if (x >= 0 && x < width && y >= 0 && y < height) {
                NodeMatrix *n = new NodeMatrix(x, y);
                obstacles->push_back(n);
                numOfObstacles--;
                *guiStr += input + "-";
            } else {
                return deleteObstacles(obstacles);
            }

        } else {
            return deleteObstacles(obstacles);
        }

    }
    return obstacles;
}



//create obstacles from the input arguments
vector<NodeMatrix*>* getGridArgs(InputParser* inputParser, long* width, long* height, string* guiStr) {
    string inputGrid;
    getline(cin, inputGrid);
    trim(inputGrid);
    if (inputParser->checkInput(regex("\\d+ \\d+"), inputGrid)) {
        *guiStr += inputGrid;
        vector<string> temp;
        boost::split(temp, inputGrid, boost::is_any_of(" "));
        *width = atol(temp[0].c_str());
        *height = atol(temp[1].c_str());
        if (*height > 0 && *width > 0) {
            return getObstacles(inputParser, *width, *height, guiStr);
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}


int main(int argc, char *argv[]) {
    long width = -1  , height = -1;
    ThreadPool* tripThreadPool= new ThreadPool(5);
    Clock* clock = new Clock();
    InputParser* inputParser = new InputParser();
    TcpServer* tcp = new TcpServer(atoi(argv[1]));
    tcp->start();
    //adding Gui as a client***********************************************************
    int guiPort = tcp->connectClient();
    //int guiPort = 0;
    TaxiCenter* taxiCenter = new TaxiCenter(clock, tcp, guiPort);


    // check th grid args
    std::string stringToGui = "";
    vector<NodeMatrix *> *obstacles = NULL;
    do {
        obstacles = getGridArgs(inputParser, &width, &height, &stringToGui);
        if (obstacles == NULL) {
            std::cout << "-1" << std::endl;
            stringToGui = "";

        }
    } while (obstacles == NULL);
    //std::cout << "gui check string:" << stringToGui << "check \\n" << std::endl;

    tcp->sendData(stringToGui, guiPort);

    // create matrix
    Matrix *grid = new Matrix((unsigned) width, (unsigned) height);
    for (int i = 0; i < obstacles->size(); ++i) {
        Node* n = (*obstacles)[i];
        grid->addObstacle(n);
        delete n;
    }
    delete obstacles;

    Menu menu = Menu(taxiCenter, grid, inputParser, tripThreadPool, guiPort, tcp);
    //run all the other inputs
    menu.run();

    delete grid;
    delete clock;
    delete tripThreadPool;
    delete taxiCenter;
    delete tcp;
    delete inputParser;
    return 0;
}