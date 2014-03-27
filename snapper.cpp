#include <iostream>
#include <fstream>
#include <string>
/*
void f()
{
    std::string line;
    while(std::getline(std::cin, line))  //input from the file in.txt
    {
        std::cout << line << "\n";   //output to the file out.txt
    }
}
*/

int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    int T, n, k;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
    std::cin >> n >> k;
    std::cout << "Case #" << i + 1 << ": ";
    if (((1 << (n-1)) ^ (k & ((1 << n)-1))) == ((1 << (n-1))-1)) {
      std::cout << "ON\n";
    } else {
      std::cout << "OFF\n";
    }
    }

    std::cin.rdbuf(cinbuf);   //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again
}
