// 2014.07.11
// kbihit�� �̿��� �ǽð� Ű���� �Է� ó��
// �̸� ���� �׸� ���߱� ���� ����

#include <iostream>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>

int main(void)
{
	// �÷��� �ð� üũ
	int start_time = (int)time(NULL);
	int end_time = 0;

	int i = 0;

	// Ŀ���� ��ġ
	int n_curcor_pos = 0;

	// �׸� �׸��� ����
	int is_draw_pickture = 1;

	// ���� ���� ����
	int n_game_play = 1;

	// �׸�
	int n_pickture[16];

	// �׸� ���̱⿡ ���� �Ǻ�����
	int n_is_view_pickture[16];

	// �׸� ����
	int n_first_select = -1;
	int n_second_select = -1;

	for (i = 0; i < 16; ++i)
	{
		n_pickture[i] = i/2;
		n_is_view_pickture[i] = 0;
	}



	// �׸� ����

	// ����Ű�� ������ ���� ����
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
						std::cout << "[��]";
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
						std::cout << " �� ";
					}
					
					
				}

				if (i % 4 == 3)
				{
					std::cout << std::endl;
				}

				is_draw_pickture = 0;
			}
		}

		// ¦ ������ ���� �Ѵ�.
		if (n_first_select != -1 && n_second_select != -1)
		{
			// ¦�� Ʋ���� ��� �ٽ� ������ ���´�.
			if (n_pickture[n_first_select] != n_pickture[n_curcor_pos])
			{
				n_is_view_pickture[n_first_select] = 0;
				n_is_view_pickture[n_second_select] = 0;

				std::cout << "<< Ʋ�Ƚ��ϴ�. >>" << std::endl;
			}
			else
			{
				std::cout << "<< ������ϴ�. >>" << std::endl;
			}

			// ���� �ʱ�ȭ
			n_first_select = -1;
			n_second_select = -1;

			// 1�� ���� ������ �ٽ� �׸���.
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
					   // �̹� ���õ� �׸��̶�� ó������ �ʴ´�.
					   if (n_is_view_pickture[n_curcor_pos] == 1)
					   {
						   break;
					   }

					   // �׸��� �����´�.
					   n_is_view_pickture[n_curcor_pos] = 1;

					   // ó�� ������ �׸��̶��?
					   if (n_first_select == -1)
					   {
						   n_first_select = n_curcor_pos;
					   }
					   // �ƴϸ�
					   else
					   {
						   n_second_select = n_curcor_pos;
					   }
				}
				break;
				
			// ESC_KEY
			case 27:
				{
					// ������ �����Ѵ�.
					std::cout << "EscKey�� �����̽��ϴ�." << std::endl;
					n_game_play = 0;
				}
				break;

			// Ư�� Ű
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

	// ���� �ϴµ� �ɸ� �ð� ���
	std::cout << end_time - start_time << "�� ���� �÷��� �ϼ̽��ϴ�." << std::endl;

	return 0;
}