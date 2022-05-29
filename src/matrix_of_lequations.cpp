#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cout;

/* global use */
vector<int> free_vars;
vector<int> free_vars_final;
vector<double> outcome;
vector<int> current_sol;


void clear_all() 
{
    free_vars.clear();
    free_vars_final.clear();
    outcome.clear();
    current_sol.clear();
}

void screen_on(vector<vector<double>> system)
{
    for (int floor = 0; floor < system.size(); floor++)
    {
        for (int item = 0; item < system[floor].size(); item++)
        {
            cout << system[floor][item] << " ";
        } cout << '\n';
    }
}

bool check_consistency(int number_of_equations, int number_of_incognizants, vector<vector<double>> system, double EPS)
{
    int counter_of_results = 0;

    for (int literal = number_of_equations - 1; literal >= 0; literal--)
    {
        if ( fabs(system[literal][number_of_incognizants]) > EPS ) 
        {
            for (int iter = 0; iter < number_of_incognizants; iter++)
            {
                if ( fabs(system[literal][iter]) < EPS ) { ++counter_of_results; }
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
        
        for (int floor = column; floor < number_of_equations; floor++)
        {
            if ( system[floor][column] > system[ultimate_index][column] )
            {
                ultimate_index = floor;
            }
        }

        if ( fabs(system[ultimate_index][column]) > EPS )
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

vector<double> get_solutions(int number_of_equations, int number_of_incognizants, vector<vector<double>> system, double EPS, vector<int> current_sol)
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
            if ( fabs(system[floor][current_item]) < EPS ) { continue; }
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

        int iter_for_free_sol = current_sol.size() - 1;
        for (int iter = number_of_incognizants - 1; iter >= 0; iter--)
        {
            if ( free_vars[iter] != -1 )
            {
                outcome.insert(outcome.begin(), current_sol[iter_for_free_sol]);
                --iter_for_free_sol;
            }

            else { outcome.insert(outcome.begin(), 0); }
        }

        for (int floor = bound - 1; floor >= 0; floor--)
        {
            temporary_box = system[floor][number_of_incognizants];

            for (int current_item = number_of_incognizants - 1; current_item >= 0; current_item--)
            {
                if ( floor == current_item )
                {
                    if ( fabs(system[floor][current_item]) < EPS ) { break; }
                    else
                    {
                        temporary_box = temporary_box / system[floor][current_item];
                        outcome[outcome.size() - counter_of_fvars] = temporary_box;
                        counter_of_fvars = 1;
                        break;
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

vector<double> get_gradation(int number_of_equations, int number_of_incognizants, vector<vector<double>> system, vector<int> current_solution) 
{
    clear_all();
    current_sol = current_solution;
    const double EPS = 1e-200;

    system = get_triangular_matrix(number_of_equations, number_of_incognizants, system, EPS);

    screen_on(system);
    cout << '\n';

    if ( check_consistency(number_of_equations, number_of_incognizants, system, EPS) )
    {
        outcome = get_solutions(number_of_equations, number_of_incognizants, system, EPS, current_sol);
    }

    for (int iter_for_fv = 0; iter_for_fv < free_vars.size(); iter_for_fv++) 
    {
        if ( free_vars[iter_for_fv] != -1 )
        {
            free_vars_final.push_back(free_vars[iter_for_fv]);
        }
    }

    for (int iter = 0; iter < outcome.size(); iter++)
    {
        outcome[iter] = round(outcome[iter] * 100) / 100; 
    }

    return outcome;
}

vector<int> get_free_vars() { return free_vars_final; }
