/* PLEASE READ ME
I am sorry for this horrendous garbage
I regret writing this code
This is supposed to be a fake crypto miner and just
look "cool" to the general "idk how to tech" public
*/

#ifndef _WIN32
#error UNSUPPORTED PLATFORM
#endif // _WIN32

#define keylength 30

#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <limits>
#include <random>
#include <time.h>
#include <windows.h>

int RANDOM(int minimum, int maximum)
{
    return ((rand() % (maximum - minimum + 1)) + minimum);
}

void SLEEP(double delay)
{
    std::chrono::time_point<std::chrono::system_clock> START, END;
    START = std::chrono::high_resolution_clock::now();
    while(true)
    {
        END = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = END - START;
        if(duration.count() >= delay)
        {
            break;
        }
    }
}

template <typename T>
T input(std::string message)
{
    T userinput;
    std::cout << message << std::endl;
    std::cout << "> ";
    std::getline(std::cin, userinput);

    while(std::cin.bad() || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "[BAD INPUT]" << std::endl;
        std::cout << "[PLEASE TRY AGAIN]" << std::endl;
        std::cout << "[Press any key to continue...]" << std::endl;
        std::cin.get();

        system("cls");

        std::cout << message << std::endl;
        std::cout << "> ";
        std::getline(std::cin, userinput);
    }

    return userinput;
}

void randomizeString(std::string &burrito)
{
    burrito = "";
    for(int x = 0; x < keylength; x++)
    {
        burrito.push_back((char)RANDOM(33, 126));
    }
}

bool printFile(std::string path)
{
    std::fstream read;
    read.open(path, std::fstream::in);
    if(read.fail())
    {
        std::cout << "failed to open " << path << std::endl;
        return false;
    }

    std::string temp;
    while(std::getline(read, temp))
    {
        std::cout << temp << std::endl;
    }
    return true;
}

int main()
{
    srand(time(0)); //for random nums
    //fullscreen && set console color
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 12); //light red
        /* https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c#:~:text=The%20simplest%20way%20you%20can,system(%22Color%20F3%22)%3B
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        // you can loop k higher to see more color choices
        for(int k = 1; k < 255; k++)
        {
        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, k);
        std::cout << k << " I want to be nice today!" << std::endl;
        }
        */

    //display logo
    printFile("resources\\logo.txt");
    SLEEP(RANDOM(3, 5)); //load "fake resources" / wait to make it seem resource heavy idk
    system("cls");
    SetConsoleTextAttribute(handle, 4); //red
        //make user input fake username and password cuz it makes this whole thing look a little cooler
    while(true)
    {
        std::string login = input<std::string>("Login");
        std::string password = input<std::string>("Password");
        if(RANDOM(0, 1) == 1)
        {
            system("cls");
            for(int x = 0; x < RANDOM(3, 5); x++)
            {
                std::cout << "Login [SUCCESSFUL]" << std::endl;
                std::cout << "STARTING CRYPTO MINER" << std::endl;
                SLEEP(0.2);
                system("cls");
                std::cout << "Login [SUCCESSFUL]" << std::endl;
                std::cout << "STARTING CRYPTO MINER." << std::endl;
                SLEEP(0.2);
                system("cls");
                std::cout << "Login [SUCCESSFUL]" << std::endl;
                std::cout << "STARTING CRYPTO MINER.." << std::endl;
                SLEEP(0.2);
                system("cls");
                std::cout << "Login [SUCCESSFUL]" << std::endl;
                std::cout << "STARTING CRYPTO MINER..." << std::endl;
                SLEEP(0.2);
                system("cls");
            }
            break;
        } else
        {
            std::cout << "\n";
            std::cout << "Login [FAILED]" << std::endl;
            std::cout << "Incorrect [USERNAME] or [PASSWORD]" << std::endl;
            std::cout << "Please try again" << std::endl;
            std::cout << "[Press any key to continue]" << std::endl;
            std::cin.get();
            system("cls");
        }
    }

    while(true)
    {
        SetConsoleTextAttribute(handle, 4); //red
        system("cls");
        for(int x = 0; x < RANDOM(3, 5); x++)
        {
            std::cout << "." << std::endl;
            SLEEP(0.2);
            system("cls");
            std::cout << ".." << std::endl;
            SLEEP(0.2);
            system("cls");
            std::cout << "..." << std::endl;
            SLEEP(0.2);
            system("cls");

        }

        system("cls");
        //generate random string/key
        std::string key = "";
        int iteration = 0;
        while(true)
        {
            SetConsoleTextAttribute(handle, 3); // blue
            std::cout << "_CRYPTO_KEY~> | ";
            SetConsoleTextAttribute(handle, 6); //gold
            randomizeString(key);
            std::cout << key;
            SetConsoleTextAttribute(handle, 3); // blue
            std::cout << " | ITERATION " << iteration << " |";
            if(RANDOM(0, 5000) == 69 && iteration >= 1000) //haha funny number go brrr haha
            {
                SetConsoleTextAttribute(handle, 10); //green
                std::cout << " SUCCESSFUL" << std::endl;
                SLEEP(3);
                break;
            } else
            {
                SetConsoleTextAttribute(handle, 4); //red
                std::cout << " UNSUCCESSFUL" << std::endl;
            }
            iteration++;
        }

        //start fake extraction process after obtaining fake key
            //idk wtf I am saying at this point.
            //The whole point of this app is just to make it look hacker-esc to anybody who is tech nooby lol
        SLEEP(RANDOM(3, 5));
        system("cls");
        SetConsoleTextAttribute(handle, 4); //red
        for(int x = 0; x < RANDOM(3, 5); x++)
        {
            std::cout << "STARTING EXTRACTION PROCESS";
            SLEEP(0.2);
            system("cls");
            std::cout << "STARTING EXTRACTION PROCESS.";
            SLEEP(0.2);
            system("cls");
            std::cout << "STARTING EXTRACTION PROCESS..";
            SLEEP(0.2);
            system("cls");
            std::cout << "STARTING EXTRACTION PROCESS...";
            SLEEP(0.2);
            system("cls");
        }
            //extraction process or whatever
            /*
            this is so cringy at this point.
            im sorry to anybody reading this rn,
            I have no idea how crypto works (at the time I wrote this horrendous code)
            and I am only making this for fun. I got a random boost of motivation to
            "practice coding" and here I am creating a fake crypto miner or whatever
            the heck this stupid thing is.

            today is 5/15/2022 1:11AM Central Daylight Time
            */
        int loadingbar = 0;
        while(loadingbar <= 100)
        {
            system("cls");
            SetConsoleTextAttribute(handle, 3); //blue
            printFile("resources\\linux penguin 2.txt");
            std::cout << "[EXTRACTING BITS]" << std::endl;
            std::cout << "LOADING ||[";
            if(loadingbar <= 50)
            {
                SetConsoleTextAttribute(handle, 4); //red
            } else if(loadingbar <= 80)
            {
                SetConsoleTextAttribute(handle, 14); //yellow
            } else if(loadingbar <= 99)
            {
                SetConsoleTextAttribute(handle, 10); //green
            } else
            {
                system("cls");
                SetConsoleTextAttribute(handle, 3);
                printFile("resources\\linux penguin 2.txt");
                std::cout << "[EXTRACTING BITS]" << std::endl;
                std::cout << "LOADING ||[";
                SetConsoleTextAttribute(handle, 10); //green
                SetConsoleTextAttribute(handle, 3);
                std::cout << "]|| " << "100" << "%" << std::endl;
                for(int x = 0; x < 100; x++)
                {
                    std::cout << "#";
                }
                SLEEP(RANDOM(2, 4));
                break;
            }
            for(int x = 0; x < loadingbar; x++)
            {
                std::cout << "#";
            }
            for(int x = 0; x < 100 - loadingbar; x++)
            {
                std::cout << " ";
            }
            SetConsoleTextAttribute(handle, 3);
            std::cout << "]|| " << loadingbar << "%" << std::endl;

            loadingbar += RANDOM(0, 10);
            double randomsleepnum = RANDOM(1, 100) * 0.01;
            SLEEP(randomsleepnum);
        }
        system("cls");
        SetConsoleTextAttribute(handle, 3); // blue
        std::cout << "Total net profit: ";
        int netprofit = RANDOM(1, 10000);
        if(netprofit <= 100)
        {
            SetConsoleTextAttribute(handle, 4); //red
        } else if(netprofit <= 1000)
        {
            SetConsoleTextAttribute(handle, 14); //yellow
        } else if(netprofit <= 5000)
        {
            SetConsoleTextAttribute(handle, 10); //green
        } else
        {
            SetConsoleTextAttribute(handle, 6); //gold
        }
        std::cout << netprofit << "$" << std::endl;
        SetConsoleTextAttribute(handle, 3); // blue
        std::cout << "[Press any key to continue...]" << std::endl;
        std::cin.get();
        system("cls");
        for(int x = 0; x < RANDOM(3, 5); x++)
        {
            std::cout << "RESTARTING CRYPTO MINER";
            SLEEP(0.2);
            system("cls");
            std::cout << "RESTARTING CRYPTO MINER.";
            SLEEP(0.2);
            system("cls");
            std::cout << "RESTARTING CRYPTO MINER..";
            SLEEP(0.2);
            system("cls");
            std::cout << "RESTARTING CRYPTO MINER...";
            SLEEP(0.2);
            system("cls");
        }
    }
}
