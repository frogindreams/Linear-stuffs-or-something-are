#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

vector<double> get_gradation(int number_of_equations, int number_of_incognizants, vector<vector<double>> system) 
{
    vector<double> outcome(number_of_incognizants, 0);
    int number_of_equations_c = 0;
    const double EPS = 1e-20;

    for (int iter_main = 0; iter_main < number_of_incognizants - 1; iter_main++) 
    {
        int lead_number = -1e-20;
        int saved_index_of_line = 0;

        for (int iter_sub = 0; iter_sub < system.size(); iter_sub++)
        {
            if ( system[iter_sub][iter_main] > lead_number ) {
                lead_number = system[iter_sub][iter_main];
                saved_index_of_line = iter_sub;
            }
        }

        if ( number_of_equations_c < number_of_equations - 1 )
        {
            std::swap( system[number_of_equations_c], system[saved_index_of_line] );
        } number_of_equations_c++;


        /* falling down */
        for (int current_line = 0; current_line < system.size() - 1; current_line++)
        {
            vector<double> secure_current_line = system[current_line];
            vector<double> lower_line = system[current_line + 1];

            double up_factor = lower_line[iter_main];
            double down_factor = secure_current_line[iter_main];

            for (int iter = 0; iter < secure_current_line.size(); iter++) 
            {
                secure_current_line[iter] *= (up_factor / down_factor);
                system[current_line + 1][iter] -= secure_current_line[iter];
            }
        }
    }

    int sub_value = 1;
    /* climbing up */
    for (int iter_main = system.size() - 1; iter_main >= 0; iter_main--)
    {
        double sum_of_line = 0;
        for (int iter_sub = 0; iter_sub < number_of_incognizants; iter_sub++)
        {
            sum_of_line += system[iter_main][iter_sub];
            cout << system[iter_main][iter_sub] << " ";
        } 
        
        sum_of_line -= system[iter_main][number_of_incognizants - sub_value];
        outcome[iter_main] = (system[iter_main][number_of_incognizants] - sum_of_line) / system[iter_main][number_of_incognizants - sub_value];

        if (iter_main != 0)
        {
            system[iter_main - 1][number_of_incognizants - sub_value] *= outcome[iter_main]; 
        }

        sub_value++;
    }

    screen_on(system);

    for (int iter_outcome = 0; iter_outcome < outcome.size(); iter_outcome++)
    {
        outcome[iter_outcome] = round(outcome[iter_outcome] * 100) / 100;
    }

    return outcome;
}
