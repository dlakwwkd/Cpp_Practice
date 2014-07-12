// 2014.07.11
// kbihit를 이용한 실시간 키보드 입력 처리
// 이를 통한 그림 맞추기 게임 제작

#include <iostream>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>

int main(void)
{
	// 플레이 시간 체크
	int start_time = (int)time(NULL);
	int end_time = 0;

	int i = 0;

	// 커서의 위치
	int n_curcor_pos = 0;

	// 그림 그리는 여부
	int is_draw_pickture = 1;

	// 게임 실행 여부
	int n_game_play = 1;

	// 그림
	int n_pickture[16];

	// 그림 보이기에 대한 판별여부
	int n_is_view_pickture[16];

	// 그림 선택
	int n_first_select = -1;
	int n_second_select = -1;

	for (i = 0; i < 16; ++i)
	{
		n_pickture[i] = i/2;
		n_is_view_pickture[i] = 0;
	}



	// 그림 섞기

	// 방향키를 움직여 게임 진행
	while (n_game_play)
	{
		if (is_draw_pickture)
		{
			for (i = 0; i < 16; ++i)
			{
				if (i == n_curcor_pos)
				{
					if (n_is_view_pickture[i] == 1)
					{
						std::cout << "[" << std::setw(2) << n_pickture[i] << "]";
					}
					else
					{
						std::cout << "[▩]";
					}
				}
				else
				{
					if (n_is_view_pickture[i] == 1)
					{
						std::cout << std::setw(3) << n_pickture[i] << " ";
					}
					else
					{
						std::cout << " ▩ ";
					}
					
					
				}

				if (i % 4 == 3)
				{
					std::cout << std::endl;
				}

				is_draw_pickture = 0;
			}
		}

		// 짝 맟춤을 판정 한다.
		if (n_first_select != -1 && n_second_select != -1)
		{
			// 짝이 틀렸을 경우 다시 뒤집어 놓는다.
			if (n_pickture[n_first_select] != n_pickture[n_curcor_pos])
			{
				n_is_view_pickture[n_first_select] = 0;
				n_is_view_pickture[n_second_select] = 0;

				std::cout << "<< 틀렸습니다. >>" << std::endl;
			}
			else
			{
				std::cout << "<< 맞췄습니다. >>" << std::endl;
			}

			// 선택 초기화
			n_first_select = -1;
			n_second_select = -1;

			// 1초 동안 쉬고나서 다시 그린다.
			Sleep(1000);
			system("cls");
			is_draw_pickture = 1;
		}

		if (_kbhit())
		{
			char key = _getch();
			
			switch (key)
			{
			// ENTER_KEY
			case 13:
				{
					   // 이미 선택된 그림이라면 처리하지 않는다.
					   if (n_is_view_pickture[n_curcor_pos] == 1)
					   {
						   break;
					   }

					   // 그림을 뒤집는다.
					   n_is_view_pickture[n_curcor_pos] = 1;

					   // 처음 선택한 그림이라면?
					   if (n_first_select == -1)
					   {
						   n_first_select = n_curcor_pos;
					   }
					   // 아니면
					   else
					   {
						   n_second_select = n_curcor_pos;
					   }
				}
				break;
				
			// ESC_KEY
			case 27:
				{
					// 게임을 종료한다.
					std::cout << "EscKey를 누르셨습니다." << std::endl;
					n_game_play = 0;
				}
				break;

			// 특수 키
			case -32:
				{
					char dir_key = _getch();
						
					switch (dir_key)
					{
					case 72:
					{
							   if (n_curcor_pos > 3)
							   {
								   n_curcor_pos -= 4;
							   }
					}
						break;
					case 80:
					{
							   if (n_curcor_pos < 12)
							   {
								   n_curcor_pos += 4;
							   }
					}
						break;
					case 75:
					{
							   if (n_curcor_pos%4 > 0)
							   {
								   --n_curcor_pos;
							   }
					}
						break;
					case 77:
					{
							   if (n_curcor_pos%4 < 3)
							   {
								   ++n_curcor_pos;
							   }
					}
						break;
					}
				}
				break;
			}

			system("cls");
			is_draw_pickture = 1;
		}
	}

	end_time = (int)time(NULL);

	// 게임 하는데 걸리 시간 출력
	std::cout << end_time - start_time << "초 동안 플레이 하셨습니다." << std::endl;

	return 0;
}