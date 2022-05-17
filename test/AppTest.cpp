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
        vector<double> outcome_test_1{ 3.33, 0.33 };

        Outcomes() {}
};

TEST(GradationTest, Test_1)
{
    Outcomes* consequence = new Outcomes;

    int number_of_conditions = 0;
    int number_of_incognizants = 0;
    vector<vector<double>> system;

    vector<double> result = get_gradation(number_of_conditions, number_of_incognizants, system);

    EXPECT_EQ(result, consequence -> outcome_test_1);
}

int main(int argc, char* argv[]) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
