#include "Music.h"

// 音名：頻率
const DWORD C = 262, Cs = 277, Db = 277, D = 294, Ds = 311, Eb = 311, E = 330, F = 349, Fs = 370,
Gb = 370, G = 392, Gs = 415, Ab = 415, A = 440, As = 466, Bb = 466, B = 494;
double DELAY = 60000;

bool Music::play = true;
thread* Music::music = NULL;

// 編輯曲目方法：
// speed = 每分鐘拍子數
// 每顆音符：{音名, 拍子長度}　（例如 {C,1}：Do一拍  {Fs,0.5}：升Fa半拍)
// 如果需要高八度就乘2 （例如C/2是低音Do Db*2*2是高兩個八度的降Re）

const vector<note> BEE = { {G,1},{E,1},{E,2},{F,1},{D,1},{D,2},
                             {C,1},{D,1},{E,1},{F,1},{G,1},{G,1},{G,2},
                             {G,1},{E,1},{E,2},{F,1},{D,1},{D,2},
                             {C,1},{E,1},{G,1},{G,1},{E,4},
                             {D,1},{D,1},{D,1},{D,1},{D,1},{E,1},{F,2},
                             {E,1},{E,1},{E,1},{E,1},{E,1},{F,1},{G,2},
                             {G,1},{E,1},{E,2},{F,1},{D,1},{D,2},
                             {C,1},{E,1},{G,1},{G,1},{C,4} },
    FAMILY_MART = { {E,0.5},{C,0.5},{G / 2,0.5},{C,0.5},{D,0.5},{G,1.5},
              {D,0.5},{E,0.5},{D,0.5},{G / 2,0.5},{C,2},
              {E,0.5},{C,0.5},{G / 2,0.5},{C,0.5},{D,0.5},{G,1.5},
              {D,0.5},{E,0.5},{D,0.5},{G / 2,0.5},{C,2},
              {E,0.5},{C,0.5},{G / 2,0.5},{C,0.5},{D,0.5},{G,1.5},
              {D,0.5},{E,0.5},{D,0.5},{G / 2,0.5},{E,0.5},{C,0.5},{D,0.5},{E,0.5} };


Music::~Music()
{
    if (music != NULL)
    {
        play = false;
        music->join();
        delete music;
    }
}

void Music::setMusic(unsigned choice)
{
    if (music != NULL)
    {
        play = false;
        music->join();
        delete music;
        music = NULL;
    }
    if (choice != 0)
    {
        
        play = true;
        switch (choice)
        {
        case 1:
            music = new thread(bind(&player, BEE, 160));
            break;
        case 2:
            music = new thread(bind(&player, FAMILY_MART, 108));
            break;
        }
    }
}

void Music::player(vector<note> song, double speed)
{
    while (play)
    {
        for (note n : song)
        {
            if (play)
            {
                Beep(n.frequency, static_cast<DWORD>(n.duration*(DELAY / speed)));
            }

        }
    }
}