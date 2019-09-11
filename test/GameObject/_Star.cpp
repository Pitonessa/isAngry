//
// Created by Emanuele Casciaro on 06/09/2019.
//

#include "GameObjects/Star/Star.h"
#include "gtest/gtest.h"
#include "iostream"
class StarFixture : public ::testing::Test {
protected:
    std::vector<Star*> starList;

    virtual void SetUp() {
        for(int i = 0; i < 1000; i++) {
            starList.push_back(new Star(3, 7));
        }
    }

    virtual void TearDown() {
        for (auto i : starList)
            delete i;
        starList.clear();
    }
};

TEST_F(StarFixture, Brightness) {
    for (auto i : starList) {
        EXPECT_GE(i->brightness, 200);
        EXPECT_LE(i->brightness, 249);
    }
}

TEST_F(StarFixture, Update) {
    for (auto i : starList) {
        int previusBrightness = i->brightness;
        i->updateBrightness();
        if (i->getGloom())
            EXPECT_EQ(previusBrightness + 1, i->brightness);
        else
            EXPECT_EQ(previusBrightness - 1, i->brightness);
    }
}