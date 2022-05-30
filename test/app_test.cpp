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
        vector<double> current_sol_default;

        vector<double> result_test_1{ 3.33, 0.33 };
        vector<int> r_free_vars_test_1;

        vector<double> result_test_2{ 1.00, 2.00, 3.00 };
        vector<int> r_free_vars_test_2;

        vector<double> result_test_3{ 4.00, 3.00, -2.00 };
        vector<int> r_free_vars_test_3;

        vector<double> result_test_4{ 1.00, 1.00, 1.00 };
        vector<int> r_free_vars_test_4;

        vector<double> result_test_5{ -79.00, 42.00, 2.00, -40.00 };
        vector<int> r_free_vars_test_5;

        vector<double> result_test_6{ 7.00, 3.00, -1.00, 6.00, 2.00, -2.00, 5.00, 1.00, -3.00, 4.00 };
        vector<int> r_free_vars_test_6;

        vector<double> result_test_7_and_8{ 1.00, 1.00, 1.00, 1.00, 1.00, 1.00 };
        vector<int> r_free_vars_test_7_and_8;

        vector<double> result_test_9;
        vector<int> r_free_vars_test_9;

        vector<double> result_test_10;
        vector<int> r_free_vars_test_10;

        vector<double> result_test_11;
        vector<int> r_free_vars_test_11;

        vector<double> result_test_12;
        vector<int> r_free_vars_test_12;

        vector<double> result_test_13{ 3.00, 0.00, 2.00 };
        vector<int> r_free_vars_test_13{ 3 };
        vector<double> current_sol_test_13{ 2.00 };

        vector<double> result_test_14{ 3.00, 0.00, 2.00 };
        vector<int> r_free_vars_test_14{ 3 };
        vector<double> current_sol_test_14{ 2.00 };

        vector<double> result_test_15{ 4.00, 1.00, 1.00 };
        vector<int> r_free_vars_test_15{ 1, 3 };
        vector<double> current_sol_test_15{ 4.00, 1.00 };

        vector<double> result_test_16{ -1.67, 1.01, 2.00, -0.67, 0.00 };
        vector<int> r_free_vars_test_16{ 4, 5 };
        vector<double> current_sol_test_16{ -0.67, 0.00 };

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

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_1.empty());
    EXPECT_EQ(result, consequence -> result_test_1);

    delete consequence;
}

TEST(GradationTest, Test_2)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 3;
    int number_of_incognizants = 3;
    vector<vector<double>> system{ {3, 5, -4, 1},
                                   {8, 1, 5, 25}, 
                                   {-3, 7, 0, 11} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_2.empty());
    EXPECT_EQ(result, consequence -> result_test_2);

    delete consequence;
}

TEST(GradationTest, Test_3)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 3;
    int number_of_incognizants = 3;
    vector<vector<double>> system{ {1, 2, 3, 4},
                                   {2, 1, 2, 7}, 
                                   {1, 1, 1, 5} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_3.empty());
    EXPECT_EQ(result, consequence -> result_test_3);

    delete consequence;
}

TEST(GradationTest, Test_4)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 3;
    int number_of_incognizants = 3;
    vector<vector<double>> system{ {1, 5, -4, 2},
                                   {80, 1, 5, 86}, 
                                   {-3, 7, 0.03, 4.03} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_4.empty());
    EXPECT_EQ(result, consequence -> result_test_4);

    delete consequence;
}

TEST(GradationTest, Test_5)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 4;
    int number_of_incognizants = 4;
    vector<vector<double>> system{ {2, 5, 4, 1, 20},
                                   {1, 3, 2, 1, 11}, 
                                   {2, 10, 9, 7, 0},
                                   {3, 8, 9, 2, 37} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_5.empty());
    EXPECT_EQ(result, consequence -> result_test_5);

    delete consequence;
}

TEST(GradationTest, Test_6)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 10;
    int number_of_incognizants = 10;
    vector<vector<double>> system{ {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 10},
                                   {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 9}, 
                                   {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 8},
                                   {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 7},
                                   {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 6},
                                   {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 5},
                                   {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 4},
                                   {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 3},
                                   {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_6.empty());
    EXPECT_EQ(result, consequence -> result_test_6);

    delete consequence;
}

TEST(GradationTest, Test_7)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 6;
    int number_of_incognizants = 6;
    vector<vector<double>> system{ {1e-14, 5, -4, 1, 1, 2, 5.00000000000001},
                                   {80, 2e-06, 5, 25, 3, 2, 115.000002},
                                   {-3, 7, 0.03, 11, 6, 1, 22.03},
                                   {6, 1, 8, 0.001, 2, 1, 18.001},
                                   {5000000, 8, 1, 9, 0.4, 1, 5000019.4},
                                   {2, 8, 9, 1, 4, 0.3, 24.3} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_7_and_8.empty());
    EXPECT_EQ(result, consequence -> result_test_7_and_8);

    delete consequence;
}

TEST(GradationTest, Test_8)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 6;
    int number_of_incognizants = 6;
    vector<vector<double>> system{ {1, 5, -4, 1, 1, 2, 6},
                                   {80, 1, 5, 25, 3, 2, 116},
                                   {-3, 7, 0.03, 11, 6, 1, 22.03},
                                   {6, 1, 8, 0.001, 2, 1, 18.001},
                                   {5000000, 8, 1, 9, 0.4, 1, 5000019.4},
                                   {2, 8, 9, 1, 4, 0.3, 24.3} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_7_and_8.empty());
    EXPECT_EQ(result, consequence -> result_test_7_and_8);

    delete consequence;
}

TEST(GradationTest, Test_9)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 2;
    int number_of_incognizants = 2;
    vector<vector<double>> system{ {1, 1, 0}, 
                                   {1, 1, 7} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_9.empty());
    EXPECT_EQ(result, consequence -> result_test_9);

    delete consequence;
}

TEST(GradationTest, Test_10)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 10;
    int number_of_incognizants = 10;
    vector<vector<double>> system{ {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 7},
                                   {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 7},
                                   {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                                   {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 7},
                                   {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 7},
                                   {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
                                   {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 7},
                                   {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 7},
                                   {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                                   {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 7} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_10.empty());
    EXPECT_EQ(result, consequence -> result_test_10);

    delete consequence;
}

TEST(GradationTest, Test_11)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 5;
    int number_of_incognizants = 3;
    vector<vector<double>> system{ {1, -1, 0, 3},
                                   {0, 1, 1, 2},
                                   {2, 1, 3, 1},
                                   {1, 1, 2, 4},
                                   {2, 1, 2, 4} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_11.empty());
    EXPECT_EQ(result, consequence -> result_test_11);

    delete consequence;
}

TEST(GradationTest, Test_12)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 2;
    int number_of_incognizants = 4;
    vector<vector<double>> system{ {1, 2, 3, 4, 5},
                                   {1, 2, 3, 4, 15} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_default);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars.empty(), consequence -> r_free_vars_test_12.empty());
    EXPECT_EQ(result, consequence -> result_test_12);

    delete consequence;
}

TEST(GradationTest, Test_13)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 3;
    int number_of_incognizants = 3;
    vector<vector<double>> system{ {1, -1, 0, 3},
                                   {0, 1, 1, 2},
                                   {0, 2, 2, 4} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_test_13);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars, consequence -> r_free_vars_test_13);
    EXPECT_EQ(result, consequence -> result_test_13);

    delete consequence;
}

TEST(GradationTest, Test_14)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 5;
    int number_of_incognizants = 3;
    vector<vector<double>> system{ {1, -1, 0, 3},
                                   {0, 1, 1, 2},
                                   {0, 2, 2, 4},
                                   {2, -2, 0, 6},
                                   {0, 2, 2, 4} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_test_14);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars, consequence -> r_free_vars_test_14);
    EXPECT_EQ(result, consequence -> result_test_14);

    delete consequence;
}

TEST(GradationTest, Test_15)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 5;
    int number_of_incognizants = 3;
    vector<vector<double>> system{ {0, 1, 1, 2},
                                   {0, 1, 1, 2},
                                   {0, 2, 2, 4},
                                   {0, 3, 3, 6},
                                   {0, 2, 2, 4} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_test_15);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars, consequence -> r_free_vars_test_15);
    EXPECT_EQ(result, consequence -> result_test_15);

    delete consequence;
}

TEST(GradationTest, Test_16)
{
    Outcomes* consequence = new Outcomes;

    int number_of_equations = 3;
    int number_of_incognizants = 5;
    vector<vector<double>> system{ {0, 1, 1, 3, 3, 1},
                                   {1, 1, 2, 2, 1, 2},
                                   {0, 1, 2, 3, 1, 3} };

    vector<double> result;
    vector<int> r_free_vars;

    result = get_gradation(number_of_equations, number_of_incognizants, system, consequence -> current_sol_test_16);
    r_free_vars = get_free_vars();

    EXPECT_EQ(r_free_vars, consequence -> r_free_vars_test_16);
    EXPECT_EQ(result, consequence -> result_test_16);

    delete consequence;
}

int main(int argc, char* argv[]) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
