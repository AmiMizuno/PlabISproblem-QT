#include <iostream>
#include <fstream>
#include <cstdlib>
#include "container.h"

using namespace std;

using namespace flora;

int main(int argc, char* argv[])
{
    if(argc != 3)	{
        cout << "incorrect command line! "
        "Waited: command infile outfile" << endl;
        exit(1);
    }
    //ifstream ifst(argv[1]);
        char s;
    ifstream ifst;
    ifst.open("in.txt");
    cout << ifst.eof();
    //ifst >> s;
    ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container c;
    init(c);
    in(c, ifst);
	ofst << "Filled container. " << endl;
	sort(c);
	out(c, ofst);
	ofst << endl;
	outTrees(c, ofst);
	clear(c);
	ofst << "Empty container. " << endl;
	out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}
