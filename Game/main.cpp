#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"
#include "Slide.h"
#include <vector>
#include <queue>
#include <stdio.h>
#include "Background.h"
#include "Object.h"
#include "Score.h"
#include <time.h>
#include "Death.h"
#include <string>
#include <stack>
#include <utility>
#include <algorithm>
#include <string.h>
#include "Enagy.h"
using namespace std;
static const float VIEW_HEIGHT = 1080.0f;
static const float VIEW_WIDTH = 1920.0f;
void Showtexet(int x, int y, string word, int size, sf::RenderWindow& window, sf::Font* font);
void updatascore(string a, int b);
void Showscoreboard (sf::RenderWindow& window);
int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "KOPIKO", sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
    sf::Texture playerTexture;
        playerTexture.loadFromFile("pic/run.png");
    sf::Texture playerSlideTexture;
        playerSlideTexture.loadFromFile("pic/run.png");
    sf::Texture slide;
        slide.loadFromFile("pic/Slide.png");
    sf::Texture num;
        num.loadFromFile("pic/num.png");
    sf::Texture mainbg;
        mainbg.loadFromFile("pic/mainbg.png");
    sf::Texture it1;
        it1.loadFromFile("pic/item1.png");
    sf::Texture BG;
        BG.loadFromFile("pic/BG2.png");
    sf::Texture s;
        s.loadFromFile("pic/s.png");
    sf::Texture m;
        m.loadFromFile("pic/m.png");
    sf::Texture l;
        l.loadFromFile("pic/l.png");
    sf::Texture monter;
        monter.loadFromFile("pic/monter.png");
    sf::Texture monterdeath;
        monterdeath.loadFromFile("pic/monterdeath.png");
    sf::Texture playTT;
        playTT.loadFromFile("pic/play.png");
    sf::Texture scoreTT;
        scoreTT.loadFromFile("pic/score.png");
    sf::Texture exitTT;
        exitTT.loadFromFile("pic/exit.png");
    sf::Texture easyTT;
        easyTT.loadFromFile("pic/easy.png");
    sf::Texture normalTT;
        normalTT.loadFromFile("pic/normal.png");
    sf::Texture hardTT;
        hardTT.loadFromFile("pic/hard.png");
    sf::Texture backTT;
        backTT.loadFromFile("pic/back.png");
    sf::Texture GOTT;
        GOTT.loadFromFile("pic/Game over.png");
    sf::Texture subTT;
        subTT.loadFromFile("pic/submit.png");
    sf::Texture DPTT;
        DPTT.loadFromFile("pic/PDead.png");
    sf::Texture rankTT;
        rankTT.loadFromFile("pic/Ranking.png");
    sf::Texture nextTT;
        nextTT.loadFromFile("pic/Next.png");
    sf::Texture NGTT;
        NGTT.loadFromFile("pic/namegame.png");
    sf::Texture standTT;
        standTT.loadFromFile("pic/stand.png");
    sf::Texture stageTT;
        stageTT.loadFromFile("pic/stage.png");
    sf::Texture monter2;
        monter2.loadFromFile("pic/monter2.png");
    sf::Texture red;
        red.loadFromFile("pic/redscreen.png");
    sf::Texture blurtt;
        blurtt.loadFromFile("pic/buar.png");
    sf::Texture resumett;
        resumett.loadFromFile("pic/resume.png");
    sf::Texture quittt;
        quittt.loadFromFile("pic/quit.png");
    sf::Texture enagytt;
        enagytt.loadFromFile("pic/enagy.png");
    sf::Font font;
        font.loadFromFile("font/itim.ttf");
    sf::Clock clock;
    sf::Vector2f direction;
    
    int status_game = 1;
    int pause = 0,go_stasus=0;
    int temp,temp_score;
    int score = 0;
    int energy = 100;
    float deltaTime = 0.0f;
    float sumTime = 0.0f;
    float scoreTime = 0.0f;
    float EnemyTime = 0.0f;
    float survivalTime = 0.0f;
    float acc = 0.0f;
    float bloodtime = -1.0f;
    float pausetime = 0.0f;
    float go = 0.0f;
    int countitem = 0;
    int onedead;
    int kmode;
    string showscore;
    string name;
    vector <Score> Scores;
    vector <Enagy> energys;
    deque <Object> coinsS, coinsM, coinsL, enemys,item1;

    for (int i = 0; i < 5; i++)   
        Scores.push_back(Score(&num,sf::Vector2f(1850.0f-i*80.0f, 100.0f)));  
    for (int i = 0; i < 5; i++)
        energys.push_back(Enagy(&enagytt, sf::Vector2f(100.0f + i * 160.0f, 100.0f)));
    
    Player player(&playerTexture, sf::Vector2u(8, 1), 0.2f, 300.0f,300.0f);
    Slide playerSlide(&slide, sf::Vector2u(5, 1), 0.2f, 300.0f);
    Background Bg(&BG,0.2f);
    Platform stage(&stageTT, sf::Vector2f(VIEW_WIDTH+200.0f, 200.0f), sf::Vector2f(VIEW_WIDTH / 2.0f, 1000.0f));
    Platform menu(&mainbg, sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT), sf::Vector2f(VIEW_WIDTH / 2.0f, VIEW_HEIGHT / 2.0f));
    Platform NG(&NGTT, sf::Vector2f(620.0f, 200.0f), sf::Vector2f(450.0f, 200.0f));
    Platform play(&playTT, sf::Vector2f(390.0f, 170.0f), sf::Vector2f(450.0f, 400.0f));
    Platform scoreB(&scoreTT, sf::Vector2f(390.0f, 170.0f), sf::Vector2f(450.0f, 600.0f));
    Platform exit(&exitTT, sf::Vector2f(390.0f, 170.0f), sf::Vector2f(450.0f, 800.0f));
    Platform easy(&easyTT, sf::Vector2f(390.0f, 170.0f), sf::Vector2f(300.0f, 200.0f));
    Platform normal(&normalTT, sf::Vector2f(390.0f, 170.0f), sf::Vector2f(300.0f, 400.0f));
    Platform hard(&hardTT, sf::Vector2f(390.0f, 170.0f), sf::Vector2f(300.0f, 600.0f));
    Platform back(&backTT, sf::Vector2f(390.0f, 170.0f), sf::Vector2f(300.0f, 800.0f));
    Platform back2(&backTT, sf::Vector2f(390.0f, 170.0f), sf::Vector2f(300.0f, 900.0f));
    Platform GameOver(&GOTT, sf::Vector2f(600.0f, 200.0f), sf::Vector2f(1300.0f, 200.0f));
    Platform submit(&subTT, sf::Vector2f(390.0f, 170.0f), sf::Vector2f(1300.0f, 800.0f));
    Platform Next(&nextTT, sf::Vector2f(390.0f, 170.0f), sf::Vector2f(1700.0f, 990.0f));
    Platform Rank(&rankTT, sf::Vector2f(600.0f, 200.0f), sf::Vector2f(1000.0f, 200.0f));
    Platform stand(&standTT, sf::Vector2f(320.0f, 400.0f), sf::Vector2f(1400.0f, 500.0f));
    Platform monmenu(&monter2, sf::Vector2f(320.0f, 400.0f), sf::Vector2f(1400.0f, 500.0f));
    Platform reds(&red, sf::Vector2f(1920.0f, 1080.0f), sf::Vector2f(1920.0f/2, 1080.0f/2));
    Platform resume(&resumett, sf::Vector2f(300.0f, 130.0f), sf::Vector2f(VIEW_WIDTH / 2.0f, 400.0f));
    Platform quit(&quittt, sf::Vector2f(300.0f, 130.0f), sf::Vector2f(VIEW_WIDTH / 2.0f, 600.0f));
    Platform blur(&blurtt, sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT), sf::Vector2f(VIEW_WIDTH / 2.0f, VIEW_HEIGHT / 2.0f));
    Platform Pause(&mainbg, sf::Vector2f(VIEW_WIDTH/2.0f, VIEW_HEIGHT / 2.0f), sf::Vector2f(VIEW_WIDTH / 2.0f, VIEW_HEIGHT / 2.0f));
    Death mondeath(&monterdeath, sf::Vector2f(160.0f, 200.0f), sf::Vector2u(7, 1), 0.15f);
    Death pdeath(&DPTT, sf::Vector2f(310.0f, 230.0f), sf::Vector2u(10, 1), 0.2f);
    
    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();
            if (status_game == 6)
            {
                if (ev.type == sf::Event::TextEntered)
                    name.push_back(ev.text.unicode);
                if (!name.empty() && name.back() == 8)
                {
                    name.pop_back();
                    if (!name.empty())
                        name.pop_back();

                }
                if (!name.empty() && !(name.back() >= 'a' && name.back() <= 'z' || name.back() >= 'A' && name.back() <= 'Z' || name.back() >= '0' && name.back() <= '9'))
                {
                    name.pop_back();
                }
            }
        }
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.0f)
                deltaTime = 1.0f / 20.0f;
       
        if (status_game == 1)
        {
            stand.UpdateP(deltaTime);
            go = 0.0f;
            go_stasus = 0;
            score = 0;
            energy = 0;
            sumTime = 0.0f;
            scoreTime = 0.0f;
            EnemyTime = 0.0f;
            survivalTime = 0.0f;
            countitem = 0;
            onedead = 0;
            pause = 0;
            player.setpositison(sf::Vector2f(200.0f, 800.0f));
            playerSlide.setpositison(sf::Vector2f(200.0f, 1500.0f));
            int x = sf::Mouse::getPosition().x;
            int y = sf::Mouse::getPosition().y;
            //text.setPosition(sf::Vector2f(1000.0f, 500.0f));
            //text.setCharacterSize(20);
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= 255.0f && x <= 645.0f && y >= 315.0f && y <= 485.0f)
                status_game = 2;
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= 255.0f && x <= 645.0f && y >= 515.0f && y <= 685.0f)
                status_game = 4;
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= 255.0f && x <= 645.0f && y >= 715.0f && y <= 885.0f)
                window.close();
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
        }
        if (status_game == 2)
        {
            monmenu.UpdateM(deltaTime);
            int x = sf::Mouse::getPosition().x;
            int y = sf::Mouse::getPosition().y;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= 105.0f && x <= 495.0f && y >= 115.0f && y <= 285.0f)
            {
                acc = 0.0f;
                status_game = 3;
                energy = 100;
                kmode = 0;
                score = 0;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= 105.0f && x <= 495.0f && y >= 315.0f && y <= 485.0f)
            {
                acc = 500.0f;
                status_game = 3;
                energy = 100;
                kmode = 10;
                score = 100;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= 105.0f && x <= 495.0f && y >= 515.0f && y <= 685.0f)
            {
                acc = 1000.0f;
                status_game = 3;
                energy = 100;
                kmode = 20;
                score = 200;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= 105.0f && x <= 495.0f && y >= 715.0f && y <= 885.0f)
                status_game = 1;
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
        }
        if (status_game == 4)
        {
            int x = sf::Mouse::getPosition().x;
            int y = sf::Mouse::getPosition().y;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= 105.0f && x <= 495.0f && y >= 815.0f && y <= 985.0f)
                status_game = 1;
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
        }
        if (status_game == 6)
        {
            int x = sf::Mouse::getPosition().x;
            int y = sf::Mouse::getPosition().y;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= 1105.0f && x <= 1595.0f && y >= 715.0f && y <= 885.0f)
            {
                char temp[100];
                strcpy(temp, name.c_str());
                if(strlen(temp)==0)
                    strcpy(temp,"unknow");
                updatascore(temp, temp_score);
                //printf("%d", temp_score);
                status_game = 1;
            }
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
        }
        //หยุดเกม
        pausetime += deltaTime;
        if (pause)
        {
            int x = sf::Mouse::getPosition().x;
            int y = sf::Mouse::getPosition().y;
            if (!go_stasus && pausetime >= 0.5f &&( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= VIEW_WIDTH / 2.0f - 150.0f && x <= VIEW_WIDTH / 2.0f + 150.f && y >= 335.0f && y <= 465.0f))
            {
                go = 3.0f;
                go_stasus = 1;
                
            }
            else if (!go_stasus && sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= VIEW_WIDTH / 2.0f - 150.0f && x <= VIEW_WIDTH / 2.0f + 150.f && y >= 535.0f && y <= 665.0f)
            {
                status_game = 1;
                pause = 0;
                pausetime = 0.0f;
            }
            if (go_stasus)
            {
                if (go >= 0.0f)
                {
                    go -= deltaTime;
                }
                else
                {
                    go = 0.0f;
                    go_stasus = 0;
                    pause = 0;
                    pausetime = 0.0f;
                }
            }
        }
        else if (pausetime >= 0.5f && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            pause = 1;
            pausetime = 0.0f;
        }
        if (!pause && bloodtime >= 0.0f)
            bloodtime += deltaTime;
        if (!pause && bloodtime >= 1.0f)
            bloodtime = -1.0f;
        if (!pause && energy>0)
        { 
            sumTime += deltaTime;
            scoreTime += deltaTime;
            EnemyTime += deltaTime;
            survivalTime += deltaTime;
        }
        //ลดพลังงานต่อวิ
        if (!pause && energy > 0 && survivalTime >= 20.0f)
        {
            survivalTime -= 20.0f;
            energy-=5;
        }
        //สุ่มเกิดอุปสรรค
        if (!pause && energy > 0 && EnemyTime >= 5.0f)
        {
            EnemyTime -= 5.0f;
            enemys.push_back(Object(&monter, sf::Vector2f(160.0f, 200.0f), 150.0f));
            sumTime -= 0.5f;
        }
        //สุ่มเกิดของ
        else if (!pause && energy > 0 && sumTime >= 0.5f&& EnemyTime <= 4.75f&& EnemyTime >= 0.25)
        {
            sumTime -= 0.5f;
            int x = rand() % 11;
            if (x < 6)
                coinsS.push_back(Object(&s, sf::Vector2f(50.0f, 50.0f), 0.0f));
            else if (x < 9)
                coinsM.push_back(Object(&m, sf::Vector2f(75.0f, 75.0f), 0.0f));
            else if (x < 10)
                coinsL.push_back(Object(&l, sf::Vector2f(100.0f, 100.0f), 0.0f));
            else if (countitem >= 40)
            {
                item1.push_back(Object(&it1, sf::Vector2f(100.0f, 100.0f), 0.0f));
                countitem -= 40;
            }
            else
                coinsS.push_back(Object(&s, sf::Vector2f(50.0f, 50.0f), 0.0f));
            if (acc <= 5000)
                acc += 10;
            countitem++;
        }
        //เพิ้มคะแนนต่อวิ
        if (!pause && energy > 0 && scoreTime >= 0.5f)
        {
            scoreTime -= 0.5f;
            score++;
        }  
        //mondeath
        if (!pause && mondeath.end == 1)
        {
            if(energy > 0)
                mondeath.Update(deltaTime, 300.0f + acc,false);
            else 
                mondeath.Update(deltaTime, 0.0f, false);
        }
        //updategame
        if (!pause && energy > 0)
        {
            
            player.Update(deltaTime, acc / 2.0f);
            playerSlide.Update(deltaTime,player.slide(), player.delays(), acc / 2.0f);
            for (Object& item : item1)
                item.Update(300.0f + acc, deltaTime);
            for (Object& coin : coinsL)
                coin.Update(300.0f+acc, deltaTime);
            for (Object& coin : coinsM)
                coin.Update(300.0f + acc, deltaTime);
            for (Object& coin : coinsS)
                coin.Update(300.0f + acc, deltaTime);
            for (Object& enemy : enemys)
                enemy.Update(300.0f + acc, deltaTime);
            
        
            Bg.Update(deltaTime,acc);
        //platform1.body.setTextureRect(oj1.uvRect);
        
        //เช็คการชน
        
            Collider playerCollision = player.GetCollider();
            Collider playerslideCollision = playerSlide.GetCollider();
            
            if (stage.GetCollider().CheckCollider(playerCollision, direction, 1.0f))
                player.OnCollosion(direction);

            for (Object& item : item1)
                if (item.GetCollider().CheckCollider(playerCollision) || item.GetCollider().CheckCollider(playerslideCollision))
                {
                    item.body.setPosition(-100.0f, item.body.getPosition().y);
                    energy += 20;
                    if(energy>100)
                        energy = 100;
                }
  
            for (Object& coin : coinsL)
                if (coin.GetCollider().CheckCollider(playerCollision)|| coin.GetCollider().CheckCollider(playerslideCollision))
                {
                    coin.body.setPosition(-100.0f, coin.body.getPosition().y);
                    score+=5;
                }

            for (Object& coin : coinsM)
                if (coin.GetCollider().CheckCollider(playerCollision) || coin.GetCollider().CheckCollider(playerslideCollision))
                {
                    coin.body.setPosition(-100.0f, coin.body.getPosition().y);
                    score+=2;
                }

            for (Object& coin : coinsS)
                if (coin.GetCollider().CheckCollider(playerCollision) || coin.GetCollider().CheckCollider(playerslideCollision))
                {
                    coin.body.setPosition(-100.0f, coin.body.getPosition().y);
                    score+=1;
                }
       
            for (Object& enemy : enemys)
                if (enemy.GetCollider().CheckCollider(playerCollision) || enemy.GetCollider().CheckCollider(playerslideCollision))
                {
                    mondeath.body.setPosition(enemy.body.getPosition().x, enemy.body.getPosition().y);
                    mondeath.getend(1);
                    mondeath.reset();
                    enemy.body.setPosition(-100.0f, enemy.body.getPosition().y);
                    energy-=20+kmode;
                    bloodtime = 0.0f;
                }
        }
        //updatescres
        if (status_game == 3)
        {
            temp = score;
            for (Score& score : Scores)
            {
                score.Update(temp % 10);
                temp /= 10;
            }
            temp = energy;
            if (temp < 0)
                temp = 0;
            for (Enagy& a : energys)
            {
                if (temp >= 20)
                    a.Update(20 / 5);
                else if(temp >= 0)
                    a.Update(temp / 5);
                else
                    a.Update(0);
                temp -= 20;
            }
        }
        //gameover
        if (status_game == 3 && energy <= 0)
        {
            if (onedead == 0)
            {
                sf::Vector2f xy = player.GetPosition();
                if(xy.y> playerSlide.GetPosition().y)
                    xy = playerSlide.GetPosition();
                xy.x -= 23.0f;
                xy.y += 10.0f;
                pdeath.reset();
                pdeath.setpositison(xy);
                pdeath.getend(1);
                onedead++;
                player.setpositison(sf::Vector2f(0.0f, 1500.0f));
                playerSlide.setpositison(sf::Vector2f(0.0f, 1500.0f));

            }
            pdeath.Update(deltaTime, 0.0f, true);
            int x = sf::Mouse::getPosition().x;
            int y = sf::Mouse::getPosition().y;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && x >= 1505.0f && x <= 1895.0f && y >= 905.0f && y <= 1075.0f)
            {
                status_game = 6;
                name.clear();
                showscore.clear();
                stack <int> temp;
                temp_score = score;
                while (score > 0)
                {
                    temp.push(score % 10 + 48);
                    score /= 10;
                }
                
                while (!temp.empty())
                {
                    x *= 10;
                    x += temp.top();
                    showscore.push_back(temp.top());
                    temp.pop();
                }
                
                
            }
            //while (sf::Mouse::isButtonPressed || sf::Keyboard::isKeyPressed);
        }

        while (!item1.empty() && (item1.front().body.getPosition().x < -10.0f|| energy <= 0))
            item1.pop_front();

        while (!coinsS.empty()&& (coinsS.front().body.getPosition().x < -10.0f || energy <= 0))
            coinsS.pop_front();
             
        while (!coinsM.empty() && (coinsM.front().body.getPosition().x < -10.0f || energy <= 0))
            coinsM.pop_front();
             
        while (!coinsL.empty() && (coinsL.front().body.getPosition().x < -10.0f || energy <= 0))
            coinsL.pop_front();

        while (!enemys.empty() && (enemys.front().body.getPosition().x < -10.0f || energy <= 0))
            enemys.pop_front();
        
        
       window.clear();
       if (status_game == 1)
       {
           menu.Draw(window);
           play.Draw(window);
           scoreB.Draw(window);
           exit.Draw(window);
           NG.Draw(window);
           stand.Draw(window);
       }
       else if (status_game == 2)
       {
           menu.Draw(window);
           easy.Draw(window);
           normal.Draw(window);
           hard.Draw(window);
           back.Draw(window);
           monmenu.Draw(window);
       }
       else if (status_game == 3 )//ปริ้นเกม
       {  
            Bg.Draw(window);
            stage.Draw(window);
            for (Object& item : item1)
                item.Draw(window);
            for (Object& coin : coinsS)
                coin.Draw(window);
            for (Object& coin : coinsM)
                coin.Draw(window);
            for (Object& coin : coinsL)
                coin.Draw(window);
            if (mondeath.end == 1)
                mondeath.Draw(window);
            for (Object& enemy : enemys)
                enemy.Draw(window);
            if (energy <= 0)
            {
                pdeath.Draw(window);
                Next.Draw(window);
            }
            else
            {
                player.Draw(window);
                playerSlide.Draw(window);
            }

            for (Score& score : Scores)
                score.Draw(window);
            for (Enagy& a : energys)
                a.Draw(window);
            if(bloodtime>=0.0f&& bloodtime<=0.25f|| bloodtime >= 0.5f && bloodtime <= 0.75f || bloodtime >= 1.0f && bloodtime <= 1.25f )
                reds.Draw(window);
            if (pause)
            {
                if (go_stasus)
                {
                    if(go>=2.0f)
                        Showtexet(900 , 300, "3", 400, window, &font);
                    else if (go >= 1.0f)
                        Showtexet(900, 300, "2", 400, window, &font);
                    else if (go >= 0.5f)
                        Showtexet(900, 300, "1", 400, window, &font);
                    else if (go >= 0.0f)
                        Showtexet(1200 / 2.0f, 300, "Go!!!", 400, window, &font);
                }
                else
                {
                    blur.Draw(window);
                    Pause.Draw(window);
                    quit.Draw(window);
                    resume.Draw(window);
                }
            }
       }
       else if (status_game == 4)
       {
           menu.Draw(window);
           Rank.Draw(window);
           back2.Draw(window);
           Showscoreboard(window);
       }
       else if (status_game == 6)
       {
            menu.Draw(window);
            GameOver.Draw(window);
            submit.Draw(window);
            Showtexet(900, 400, "Score : ", 100, window, &font);
            Showtexet(900, 550, "Name : ", 100, window, &font);
            Showtexet(1200, 400, showscore, 100, window, &font);
            if(name.empty())
                Showtexet(1200, 550, "Enter name", 100, window, &font);
            else
                Showtexet(1200, 550, name, 100, window, &font);
       }
       window.display();
    }
    return 0;
}

void Showtexet(int x, int y, string word, int size, sf::RenderWindow& window, sf::Font* font)
{
    sf::Text text;
    text.setFont(*font);
    text.setPosition(x, y);
    text.setString(word);
    text.setCharacterSize(size);
    window.draw(text);
}

void updatascore(string a, int b)
{
    FILE* fp;
    char temp[255];
    int score[6];
    string name[6];
    vector <pair<int, string>> userScore;
    fp = fopen("font/score.txt", "r");
    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s", &temp);
        name[i] = temp;
        fscanf(fp, "%d", &score[i]);
        userScore.push_back(make_pair(score[i], name[i]));
    }
    name[5] = a;
    score[5] = b;
    userScore.push_back(make_pair(score[5], name[5]));
    sort(userScore.begin(), userScore.end());
    fclose(fp);
    fopen("font/score.txt", "w");
    for (int i = 5; i >= 1; i--)
    {
        strcpy(temp, userScore[i].second.c_str());
        fprintf(fp, "%s %d\n", temp, userScore[i].first);
    }
    fclose(fp);
}

void Showscoreboard(sf::RenderWindow& window)
{
    sf::Font font;
        font.loadFromFile("font/itim.ttf");
    FILE* fp;
    char temp[255];
    int score[6];
    string name[6];
    fp = fopen("font/score.txt", "r");
   for (int i = 0; i < 5; i++)
    {
        char no[3] = { '1' + i };
        no[1] = '.';
        no[2] = '\0';
        Showtexet(700, 350 + 100 * i, no, 50, window, &font);
        fscanf(fp, "%s", &temp);
        Showtexet(750, 350 + 100 * i, temp, 50, window, &font);
        fscanf(fp, "%d", &score[i]);
        char sc[10];
        int k = 0,j;
        if(score[i] == 0)
            sc[k++] = 48;
        while (score[i] > 0)
        {
            sc[k++]= score[i] % 10 + 48;
            score[i] /= 10;
        }
        sc[k] = '\0';
        char show[10];
        for ( j = 0; j < strlen(sc); j++)
        {
            show[j] = sc[strlen(sc) - 1 - j];
        }
        show[j] = '\0';
        Showtexet(1100, 350 + 100 * i, show, 50, window, &font);
    }
   fclose(fp);
    
}