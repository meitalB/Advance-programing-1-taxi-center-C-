#include "sockets/Udp.h"
#include "core/Matrix.h"
#include "TaxiCenter.h"
#include "Menu.h"


int main(int argc, char *argv[]) {


    int portNum = atoi(argv[1]);
    Udp* udp = new Udp(true, portNum);
    //udp.initialize();

    Clock* clock = new Clock();
    TaxiCenter* taxiCenter = new TaxiCenter( clock);
    int width, height;

    //grid initialize grid and add obstacles if there are any.
    std::cin >> width >> height;
    Matrix* grid = new Matrix(width, height);

    Menu menu = Menu(taxiCenter, grid, clock, udp);
    //run all the other inputs
    menu.run();

    delete grid;
    delete udp;
    delete clock;
    delete taxiCenter;
    return 0;
}

