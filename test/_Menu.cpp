//
// Created by Emanuele Casciaro on 07/09/2019.
//

#include <iostream>
#include "gtest/gtest.h"
#include "GUI/Menu/Menu.h"

class MenuFixture : public ::testing::Test {
protected:
    std::vector<MenuItem*> centerdList;
    std::vector<MenuItem*> topList;
    std::vector<MenuItem*> pauseList;

    Menu *centerd, *top, *pause;

    virtual void SetUp() {
        centerdList.push_back(new MenuItem(MenuItem::TYPE::START));
        centerdList.push_back(new MenuItem(MenuItem::TYPE::SCORE));
        centerdList.push_back(new MenuItem(MenuItem::TYPE::EXIT));
        centerd = new Menu(centerdList, Menu::STYLE::TOP);

        topList.push_back(new MenuItem(MenuItem::TYPE::INFO));
        topList.push_back(new MenuItem(MenuItem::TYPE::SCORE));
        top = new Menu(topList, Menu::STYLE::TOP);

        pauseList.push_back(new MenuItem(MenuItem::TYPE::RESUME));
        pauseList.push_back(new MenuItem(MenuItem::TYPE::QUIT));
        pause = new Menu(pauseList, Menu::STYLE::CENTERED);


    }

    virtual void TearDown() {
        delete centerd;
        delete top;
        delete pause;
    }
};

TEST