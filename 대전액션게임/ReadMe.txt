﻿========================================================================
	콘솔 응용 프로그램 : 대전액션게임 프로젝트 개요
========================================================================

* 프로젝트 시작: 2014.07.11
* 제작: NHN NEXT 141033 박수빈

* 목표(지향점):
	1. 콘솔 창에서 실시간 대전 액션 게임을 만든다.
	2. 싱글플레이: 대량의 몹 잡기, 멀티플레이: 1:1 대전
	3. 빠르고 직관적인 게임 플레이, 인터페이스 구현
	4. 다양한 스킬, 캐릭터 특성 구현
	5. 컬러, 사운드의 적극적 활용

========================================================================
		패치 로그
========================================================================


=== 2014.08.19 - v.0.12 ===

* 모든 자료구조의 자료형을 포인터형으로 치환
* 뭉치는 몹 이동 제대로 안되던 문제 수정
* 히트 딜레이에도 시간기반 프레임 방식 적용
* 몹 잡을 시 최대 체력 상승량의 반만큼 체력 회복되도록 수정
* 플레이어에 따른 스킬 큐, 더미 큐 분리로 스킬 동시 시전 가능하게 함
* 2p 플레이에서 히트 판정시의 렉 개선
* 필터(폴더) 분류 세분화
* 전반적인 코드 리펙토링
* enum 한 파일로 통합, Frame, GameManager, Menu 클래스 추가

* 문제점: 리펙토링이 그다지 성공적이지 못한 것 같음, 오히려 설정 메뉴 등에 문제가 발생함..
-> 이 참에 여러 책을 참고하여 다양한 변화를 시도해봐야겠음

* 예정사항: 윈 API와 다이렉트X를 도입해볼 생각.


=== 2014.08.08 - v.0.11 ===

* 시간기반 프레임 방식으로 변경 (아직 전부 변경은 안됨)
* Player, Team 클래스 제거, 일단 enum을 통해 플레이어 구분
* 네이밍 규칙 재정립 (함수: DaeMunZa, 변수: soMunZa, 멤버변수: m_MunZa, 매개변수: under_bar)
* 인클루드 관계 재정립 (stdafx.h에 전부 몰아놨던 방식에서 각 cpp파일 마다 인클루드 하는 식으로)

* 문제점: 기초 실력 부족으로 코드의 효율성, 간결성이 많이 부족한 것 같다.
-> 새로운 기능 추가보다는 일단 기존 코드를 리팩토링 하면서 기초 실력을 다듬어야겠음.

* 예정사항: 요즘 다른 공부 때문에 시간을 거의 못쓰고 있음, 잠시 보류 상태로 있을 듯..


=== 2014.08.02 - v.0.10 ===

* 전반적인 클래스 내부구조 변경
* Team 클래스, Player 클래스, key 클래스 추가 (유닛의 has-a 관계로)
* STL map 자료구조 도입
* 2P 플레이 모드 구현
* 2P 플레이 구현에 따른 다방면에서의 코드 변경이 이루어짐
* 체력, 마나 리젠이 최대량을 잠깐이나마 넘어가는 버그 수정

* 문제점: 한 쪽이 조준모드(x키)를 켜면 다른 한쪽은 공격이 불가능한 점
-> 현재 스킬 구현의 매커니즘 상 동시에 사용하면 오류 발생 위험이 높음, 구조를 바꿀 필요가 있음

* 예정사항: 동시에 스킬 사용이 가능하도록 고민 중, 커맨드 변경 메뉴 추가 예정


=== 2014.07.25 - v.0.09 ===

* 일시정지, 게임오버 시 글씨 쓰면 보이던 것 수정
* 몹 인공지능 개선 (난이도에 비례한 확률로 영웅 위치로 돌진함)
* 스킬 이펙트 깨짐 현상 방지
* 영웅 체력 리젠, 마나 리젠량 상향
* 간혹 체력, 마나 리젠이 최대량을 넘기는 버그 수정
* 몇몇 자잘한 버그 수정

* 문제점: 하드코딩의 잔재가 좀 많이 있지만, 이제 좀 게임의 면모를 갖춘 것 같다!
-> 코드를 예쁘게하는 것은 일단 제쳐두고..뭔가 새로운 걸 더 넣어봐야겠다.

* 예정사항: 오랫동안 예정만 해왔던, 새로운 유닛, 새로운 스킬을 만들어볼 시간!


=== 2014.07.25 - v.0.08 ===

* 기본 공격 3 프레임 -> 2 프레임으로 조정, 마나 감소량 감소
* 저사양 옵션 기능 개선 (출력 분리 말고 타격이펙트 등의 색 제거로 변경)
* 게임 스피드 조절 기능 개선
* 조작감 개선 (가속도 수치 변경)
* 인공지능 개선, 몹 이동 가속도 수치 변경
* 난이도 선택지 추가
* 함수, 변수 이름 규칙 재설정
* 키 입력 함수 변경(동시 입력 가능하게 됨)
* 이동속도 최대치 설정
* 컬러 출력 알고리즘 변경으로 처리 속도 매우 향상
* 게임 설정 메뉴 추가, 게임 일시정지, 게임 오버 화면 추가
* 콘솔창 크기 확대
* 영웅 체력 증가율 상향
* 마나 회복속도 증가율 상향

* 문제점: 엔터시 가끔식 줄바뀜이 생기는 현상, 구석에서 스킬 이펙트 깨지는 현상
-> 해결방법을 좀 더 고민해봐야 겠음

* 예정사항: 위의 문제 해결, 새로운 스킬 추가, 몹 인공지능 향상 시도 예정


=== 2014.07.21 - v.0.07 ===

* 새로운 프레임 안정화 알고리즘 구현
* 스킬 이펙트 개선
* 몹 벨런스 조정
* 체력, 마나 리젠 속도 최대 체력에 비례하도록 수정
* 영웅 부활 시 최대 체력으로 부활하도록 수정
* 타격 이펙트 추가
* 사망 이펙트 개선
* 영웅 타격 딜레이 늘림
* 난이도에 따른 AI의 움직일 확률, 데미지, 체력 증가 비율 변화
* 전반적인 리팩토링 (최대한 캡슐화 하도록 노력함)
* 저사양 옵션 기능 추가
* 게임 스피드 조절 기능 추가(최대 프레임 설정)

* 문제점: 몹 사망시 핏자국이 너무 빨리 사라져서 잘 안보인다, 맥북에선 너무 느리다..
-> 시체 클래스를 만들어 볼까 생각 중, 최적화 할 방법을 계속 고민하고 있음...

* 예정사항: 일단 시체 클래스 만들어보고, 스킬 한두개 정도 더 추가하고, 새로운 영웅을 만들어봐야겠다.
	그리고 메뉴를 완전히 뜯어 고치고, 게임 실행 시 첫 화면에서 몹이 돌아다니는 영상을 재생할 생각 중..
	설정 메뉴에서 게임 스피드, 저사양 옵션, 화면 크기 변경, 몹 패턴 변화 등의 설정을 할 수 있도록 할 예정


=== 2014.07.20 - v.0.06 ===

* 프레임 유지 함수 개선
* m_Hp 상태바 추가
* Unit 클래스 리팩토링
* POINT, RECT 자료형 도입
* POINT_D 자료형 새로 만듦
* Hero 클래스 파일 분리
* Skill 클래스 추가
* 몹 AI 개선 (BossAI에서 몹 숫자에 따른 확률의 변화로 좀 더 그럴듯한 움직임 구현)
* PrintText 함수 개선 (printf -> putch 로 속도 향상)
* putch 사용으로 화면엔 아스키문자만 표현 가능하게 돼서 영웅 모양 변경
* 현재 살아있는 몹의 숫자 실시간 표시
* 색상 변경
* 몹 사망시 핏자국 생김 구현
* 스킬에 Queue 개념 도입
* Z, X, C 스킬 완성
* 스태이지 진행 구현
* 상단바 내용 입력
* 마나 추가
* 체력, 마나 수치 표시 방법 백분율에서 실제량으로 변경
* 게임 오버 화면 구현
* 생명 개념 도입
* 체력, 마나 리젠 구현
* 난이도 구현
* 콘솔창 크기 변경(세로 축소)

* 문제점: 프레임이 일정하게 유지되지 않음
-> 프레임 안정화를 위한 방법을 찾아봐야겠음

* 예정사항: 기본적인 틀은 갖춰졌으니, 벨런스와 안정화에 초점을!(그리고 차차 영웅도 추가할 계획)


=== 2014.07.18 - v.0.05 ===

* 유니코드로 변환 시도했다가 속도가 너무 느려져서 취소
* 몹은 특수문자가 아닌 1바이트 문자로 표현하여 깨짐현상 방지
* 프레임 수치 출력
* 메뉴 개수 저장 방법 변경(_countof 도입)
* 몹 AI 두 종류 동시 구현(분산, 뭉침)
* Print 클래스 개선
* 대략적인 상태 바 형태 잡음
* 프레임 60으로 유지하기 위한 함수 추가
* 이외에 몇 가지 자잘한 수정

* 문제점: 지저분한 코드가 좀 많아서 리팩토링이 시급 (특히 Unit 클래스)
-> ㅠㅠㅠㅠ 빨리 진도 나가고 싶다!

* 예정사항: 아래 예정사항과 동일..


=== 2014.07.14 - v.0.04 ===

* 화면 출력 방법 변경을 위해 Print라는 클래스 만듦
* cout이 printf보다 현저한 속도저하가 있어 printf로 변경
* 화면 출력 관련하여 이런저런 수정
* 실수로 발생한 몹의 뭉침 현상이 마치 보스몹과도 같아보여 일단 그대로 둠

* 문제점: 유닛이 겹치면 깨지는 현상, 하드코딩의 잔재들..
-> 차근차근 리팩토링 해나가자

* 예정사항: 슬슬 리팩토링 해가면서 인터페이스, 스킬 등을 추가볼 계획


=== 2014.07.13 - v.0.03 ===

* 소스 파일, 헤더 파일 세분화
* 이름 짓는 방식 "ab_cd" -> "abCd" 이런 식으로 변경
* 메인 메뉴 인터페이스 임시로 구현
* 영웅 하위 클래스 추가
* vector 등의 새로운 개념 도입
* 전반적인 코드 리팩토링
* 스킬 이펙트 미묘한(?) 변화
* 오늘 총합 10시간 정도 걸린듯..ㅠ(파일 세분화가 이렇게 힘들줄이야..)

* 문제점: 구석에서 스킬 깨지는 현상, system("cls")가 생각보다 렉이 심한 것,
	몹 한 마리가 안 죽는거, 등등.. 너무 많다;;
-> 차차 해결해야지..

* 예정사항: 클래스 부분은 아직 리팩토링하지 못했..지만 일단 출력 방법 변경부터..


=== 2014.07.12 - v.0.02 ===

* 마우스 입력 방식 -> 키보드 조작 방식으로 변경
* kbhit, getch 함수를 통한 실시간 키보드 조작 구현
* 캐릭터의 이동속도에 따른 부드러운 이동 구현
* 테스트 용도의 공격 스킬 구현
* 유닛 죽으면 화면에서 사라지는 것 구현

* 문제점: 각 유닛 마다 매번 따로 출력하고 있어서 보이는 유닛 수에 따른 속도의 차이가 심함
-> 좌표값만 따로따로 움직이고, 출력은 한번에 하는 식으로 변경 예정

* 예정사항: 전반적인 코드 리팩토링을 해야할 듯, cpp파일을 여러개로 분할도 해볼까 생각 중


=== 2014.07.11 - v.0.01 ===

* 기본적인 틀 구성, 유닛, 영웅 클래스 생성
* 테스트 용도의 몹 20마리 구현 (랜덤으로 움직이는 기초적인 AI 구현)
* 마우스 클릭을 통한 유닛 이동 구현
* 콘솔 창 크기 확대 기능 추가

* 문제점: 마우스가 가만히 있으면 입력 대기 현상 발생
-> 입력 버퍼 체크 함수를 찾으면 될 것 같은데 찾지 못하고 있음.