#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;

void screen_on(vector<vector<double>> system) 
{
    cout << '\n';

    for (int iterY = 0; iterY < system.size(); iterY++) 
    {
        for (int iterX = 0; iterX < system[iterY].size(); iterX++) 
        {
            cout << system[iterY][iterX] << " ";
        }

        cout << '\n';
    }

    cout << '\n';
}

bool check_consistency(int number_of_equations, int number_of_incognizants, vector<vector<double>> system, double EPS)
{
    int counter_of_results = 0;

    for (int literal = number_of_equations - 1; literal >= 0; literal--)
    {
        if ( abs(system[literal][number_of_incognizants]) > EPS ) 
        {
            for (int iter = 0; iter < number_of_incognizants; iter++)
            {
                if ( abs(system[literal][iter]) < EPS ) { ++counter_of_results; }
                else { break; }
            }
        }

        else { continue; }
        if ( counter_of_results == number_of_incognizants ) { return false; }
        else 
        {
            counter_of_results = 0;
            continue;
        }
    }

    return true;
}

void get_triangular_matrix(int number_of_equations, int number_of_incognizants, vector<vector<double>> system, double EPS)
{
    int ultimate_index;
    double factor;

    for (int column = 0; column < number_of_equations - 1; column++)
    {
        ultimate_index = column;
        
        for (int floor = 0; floor < number_of_equations; floor++)
        {
            if ( system[floor][column] > system[ultimate_index][column] )
            {
                ultimate_index = floor;
            }
        }

        if ( abs(system[ultimate_index][column] > EPS) )
        {
            if ( ultimate_index != column )
            {
                system[column].swap(system[ultimate_index]);
            }

            for (int floor_for_factor = column + 1; floor_for_factor < number_of_equations; floor_for_factor++)
            {
                factor = system[floor_for_factor][column] / system[column][column];

                for (int item_in_line = column; item_in_line < number_of_incognizants + 1; item_in_line++)
                {
                    if ( item_in_line != column )
                {
                        system[floor_for_factor][item_in_line] -= factor * system[column][item_in_line];
                    }

                    else { system[floor_for_factor][item_in_line] = 0; }

                    screen_on(system);
                }
            }
        }
    }
}

vector<double> get_gradation(int number_of_equations, int number_of_incognizants, vector<vector<double>> system) 
{
    vector<double> outcome(number_of_incognizants, 0);
    const double EPS = 1e-20;

    get_triangular_matrix(number_of_equations, number_of_incognizants, system, EPS);

    return outcome;
}
