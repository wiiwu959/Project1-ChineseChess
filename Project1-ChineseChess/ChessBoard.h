#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Chess.h"
using std::cout;
using std::string;
using std::vector;
using std::fstream;
using std::ios;
class ChessBoard
{
private:
    // 整個棋盤的現在的位置上的內容
    // 用指標存取，NULL就是當前位置沒有棋子的狀態
    Chess* wholePosition[9][10];//[col][row]
    // Black:0 Red:1
    int turns;


public:
    ChessBoard();
    ~ChessBoard();
    ChessBoard(string fileTxt);

    // 印出空白棋盤
    void printEmptyPlane();
	// 印出普通棋盤
    void printThePlane();
	// 印出含有選中棋的可動步數的棋盤，使用前需要先確定legalMove內是否已排除拐馬步
	// 或其他特殊規則，以及不能吃得棋，以及被其他棋檔到的剩餘位置
	void printChosenPlane();
    // 印出當前的turn
    void printTurn();


	// 移動棋盤，偵測到選棋時會呼叫
	void moveTheChess(int fromX, int fromY, int toX, int toY);
    // 改變turn
    void changTurn();

    // 應該在讀入棋盤時創建好所有chess物件
    void readTheBoard(string fileTxt);
    void saveTheBoard(string fileTxt);
	void saveTheBoard();

	vector <position> legalMove;	//存放能走的路，UI能直接使用到它
	void manageLegalMove(int x, int y);		// UI在選擇棋子以後呼叫的
	void clearLegalMove();
	void SetColor(int = 7);//搬UI的函數過來設定顏色
    void SetPosition(position);// 設定游標位置
    
    // 以位置取得棋子指標
    Chess* getChess(position);
    // 取得當下的turn
    int getTurn();
};
position cursorToChess(position);
position chessToCursor(position);

#endif // !CHESSBOARD_H