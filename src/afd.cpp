#include <iostream>
#include <vector>
#include <iterator>
#include <limits>
#include <algorithm>
#include <chrono>
#include <thread>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "colores.h"
#define luint64 long unsigned int

int afd()
{   
    std::string line;
    std::ifstream file("./test/afd/afd_test001");
    
    // Q (States) -----------------------------------------------
    std::string num_states;
    std::string state;
    std::vector<std::string> Q; // Store states
    
    std::getline(file, num_states);
    
    for( int i = 0; i < std::stoi(num_states); i++ ) {
        state = "q" + std::to_string(i);
        Q.push_back(state);
    }

    std::cout << GREEN << "[States]\n" << RESET;
    for( luint64 i = 0; i < Q.size(); i++ ) { std::cout << Q[i] << ' '; }
    std::cout << '\n';


    // Σ (Alphabet) ----------------------------------------
    char c;
    std::string alph;
    std::vector<char> E;

    std::getline(file, alph);

    std::istringstream chars(alph);
    while ( chars >> c ) { E.push_back(c); }

    std::cout << GREEN << "\n[Alphabet]\n" << RESET;
    for( luint64 i = 0; i < E.size(); i++ ) { std::cout << E[i] << ' '; }
    std::cout << '\n';
    

    // δ (Transition table) ---------------------------------------------------
    std::string t;
    std::string row_elements;
    std::vector<std::string> row;
    std::vector<std::vector<std::string>> AFD;
  
    for(luint64 i = 0; i < Q.size(); i++) {

        std::getline(file, row_elements);
         
        std::istringstream line(row_elements);

        while( line >> t ) {
            row.push_back(Q[std::stoi(t)]);
        }
        
        AFD.push_back(row);
        row.clear();     
    }

    std::cout << GREEN << "\n[Transition table]\n" << RESET;

    std::cout << "   | ";
    
    for( luint64 i = 0; i < E.size(); i++ ) {
        std::cout << E[i] << "  ";
    } std::cout << '\n';
   
    std::cout << "---+"; 
    for( luint64 i = 0; i < E.size(); i++ ) {
        std::cout  << "---";
    } std::cout << '\n';

    for( luint64 i = 0; i < AFD.size(); i++ ) {
        std::cout << Q[i] << " | ";
        for( const std::string &s : AFD[i] ) {
            std::cout << s << ' ';
        }
        std::cout << '\n';
    }
    
    // Qi (Initial state) -------------------------------------------------------------------
    std::string n;
    std::string Qi;

    std::getline(file, n);
    Qi = Q[std::stoi(n)];
    
    std::cout << GREEN << "\n[Initial state]\n" << RESET;
    std::cout << Qi;
    std::cout << '\n';
 
    // F (Final states) ------------------------------------------------------------------
    std::string s;
    std::string final_states;
    std::vector<std::string> F;

    std::getline(file, final_states);

    std::istringstream fstates(final_states);
    
    while ( fstates >> s ) {
        int index = std::stoi(s);
        F.push_back(Q[index]);
    }
    
    std::cout << GREEN << "\n[Final states]\n" << RESET; 
    for(const std::string &s : F) std::cout << s << ' ';
    std::cout << '\n';
     
    // Testing words --------------------------------------------
    bool flag;
    std::string num_words;
    std::string Qa;
    std::string word;
    std::vector<std::string> process;

    std::getline(file, num_words);
    
    std::cout << GREEN << "\n[Testing words]\n" << RESET; 
    for(int i = 0; i < std::stoi(num_words); i++) {
        Qa = Qi;

        std::getline(file, word);
        std::cout << word << ' ';

        if ( word == "q" ) { break; }

        for ( const char &c : word ) {
            process.push_back(Qa);
            auto it = std::find(E.begin(), E.end(), c);
            if( it != E.end() ) {
                int row = std::stoi(Qa.substr(1));
                int col = std::distance(E.begin(), it);
                
                if ( AFD[row][col] != "V" ) {
                    Qa = AFD[row][col];
                } else {
                    Qa = "V";
                    process.push_back(Qa);
                    break;
                }
            } else {
                Qa = "V";
                process.push_back(Qa);
                break;
            }
            
        }

        flag = std::find(F.begin(), F.end(), Qa) != F.end();
        
        if( flag ) {
            std::cout << GREEN << "SI" << RESET << '\n';
        } else {
            std::cout << RED << "NO" << RESET << '\n';
        }
        
        std::cout << "[";
        for(const std::string &p : process) {
            std::cout << " -> " << p;
        } std::cout << "]\n";

        process.clear();
    }

    file.close(); 
    getchar();
    return 0;
}
