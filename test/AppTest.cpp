#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "../include/lmodules.h"

using std::vector;

class Outcomes
{
    private:
        /* */
    public:
        vector<double> result_test_1{ 3.33, 0.33 };
        vector<int> r_free_vars_test_1;

        vector<double> result_test_2{ 1.0, 2.0, 3.0 };
        vector<int> r_free_vars_test_2;

        Outcomes() {}
};

TEST(GradationTest, Test_1)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 2;
    int number_of_incognizants = 2;
    vector<vector<double>> system{ {1, 2, 4},
                                   {2, 1, 7} };
    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_1.empty());
    EXPECT_EQ(result, consequence -> result_test_1);

    delete consequence;
}

/*
TEST(GradationTest, Test_2)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 3;
    int number_of_incognizants = 3;
    vector<vector<double>> system{ {3, 5, -4, 1},
                                   {8, 1, 5, 25}, 
                                   {-3, 7, 0, 11} };

    vector<double> result = get_gradation(number_of_equations, number_of_incognizants, system);

    EXPECT_EQ(result, consequence -> outcome_test_2);
    delete consequence;
}
*/

int main(int argc, char* argv[]) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
