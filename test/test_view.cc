#include <gtest/gtest.h>
#include <iostream>

#include "mwod/view/view.h"

TEST(displayTime, displayTime) {
    // Step 1: Save the original stdout buffer
    std::streambuf* originalCoutStreamBuf = std::cout.rdbuf();
    // Step 2: Redirect stdout to a string stream
    std::ostringstream strCout;
    std::cout.rdbuf(strCout.rdbuf());
    // Step 3: Call the function that prints to stdout
    displayTime(12, 34, 56);
    // Step 4: Restore the original stdout buffer
    std::cout.rdbuf(originalCoutStreamBuf);

    // Step 5: Verify the output
    std::string output = strCout.str();
    EXPECT_EQ(output, "12:34:56\n");
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
