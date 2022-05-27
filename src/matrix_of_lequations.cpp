#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cout;

/* global use */
vector<int> free_vars;
vector<double> outcome;


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

vector<vector<double>> get_triangular_matrix(int number_of_equations, int number_of_incognizants, vector<vector<double>> system, double EPS)
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
                }
            }
        }
    }

    return system;
}

vector<double> get_solutions(int number_of_equations, int number_of_incognizants, vector<vector<double>> system, double EPS)
{
    int counter_of_fvars = 0;
    double temporary_box;
    
    for (int iter_for_fv = 0; iter_for_fv < number_of_incognizants; iter_for_fv++)
    {
        free_vars.push_back(iter_for_fv + 1);
    }

    for (int floor = number_of_equations - 1; floor >= 0; floor--)
    {
        for (int current_item = 0; current_item < number_of_incognizants; current_item++)
        {
            if ( abs(system[floor][current_item]) < EPS ) { continue; }
            else
            {
                ++counter_of_fvars;
                if ( counter_of_fvars == 1 )
                {
                    free_vars[current_item] = -1;
                }
            }
        }

        counter_of_fvars = 0;
    }

    for (int iter_for_fv = 0; iter_for_fv < free_vars.size(); iter_for_fv++)
    {
        if ( free_vars[iter_for_fv] != -1 ) { ++counter_of_fvars; }
    }

    if ( !counter_of_fvars )
    {
        free_vars.clear();
        counter_of_fvars = 1;

        for (int floor = number_of_incognizants - 1; floor >= 0; floor--)
        {
            temporary_box = system[floor][number_of_incognizants];

            for (int current_item = number_of_incognizants - 1; current_item >= 0; current_item--)
            {
                if ( floor == current_item )
                {
                    temporary_box = temporary_box / system[floor][current_item];
                    break;
                }

                else
                {
                    temporary_box -= system[floor][current_item] * outcome[outcome.size() - counter_of_fvars];
                    ++counter_of_fvars;
                }
            }

            outcome.insert(outcome.begin(), temporary_box);
            counter_of_fvars = 1;
        }

        return outcome;
    }

    else
    {
        counter_of_fvars = 1;
        int bound;

        if ( number_of_equations <= number_of_incognizants )
        {
            bound = number_of_equations;
        } else { bound = number_of_incognizants; }

        for (int floor = bound - 1; floor >= 0; floor--)
        {
            temporary_box = system[floor][number_of_incognizants];

            for (int current_item = number_of_incognizants - 1; current_item >= 0; current_item--)
            {
                if ( floor == current_item )
                {
                    if ( abs(system[floor][current_item]) < EPS ) { break; }
                    else
                    {
                        temporary_box = temporary_box / system[floor][current_item];
                        outcome.insert(outcome.begin(), temporary_box);
                    }
                }

                else
                {
                    temporary_box -= system[floor][current_item] * outcome[outcome.size() - counter_of_fvars];
                    ++counter_of_fvars;
                }
            }
        }
    }

    return outcome;
}

vector<double> get_gradation(int number_of_equations, int number_of_incognizants, vector<vector<double>> system) 
{
    const double EPS = 1e-20;

    system = get_triangular_matrix(number_of_equations, number_of_incognizants, system, EPS);

    if ( check_consistency(number_of_equations, number_of_incognizants, system, EPS) )
    {
        outcome = get_solutions(number_of_equations, number_of_incognizants, system, EPS);

        /* deleting unnecessary stuffs */
        for (int iter_for_fv = 0; iter_for_fv < free_vars.size(); iter_for_fv++) 
        {
            if ( free_vars[iter_for_fv] == -1 )
            {
                free_vars.erase(free_vars.begin() + iter_for_fv);
            }
        }
    }

    for (int iter = 0; iter < outcome.size(); iter++)
    {
        outcome[iter] = round(outcome[iter] * 100) / 100; 
    }

    return outcome;
}

vector<int> get_free_vars() { return free_vars; }
