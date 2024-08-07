  ![](./media/image1.png)

#   소셜 샘플

*이 샘플은 Microsoft 게임 개발 키트와 호환 가능(2020년 6월)*

# 

# 설명

이 샘플에서는 Microsoft GDK(게임 SDK)에서 제공하는 소셜 관리자 C-API를
보여 줍니다.

이 샘플에는 다음에 대한 시나리오가 포함되어 있습니다.

-   사용자 추가 및 그룹 만들기

-   필터를 기반으로 소셜 그룹 검색

-   소셜 관리자 이벤트에 응답

# 샘플 빌드

-   Xbox One 개발 키트를 사용하는 경우 활성 솔루션 플랫폼을
    **Gaming.Xbox.XboxOne.x64**로 설정합니다.

-   Project Scarlett를 사용하는 경우 활성 솔루션 플랫폼을
    **Gaming.Xbox.Scarlett.x64**로 설정합니다.

*자세한 내용은 GDK 설명서에서* 샘플 실행을 *참조하세요.*

# 샘플 사용

샘플은 표준 게임 패드 또는 키보드를 사용하여 제어됩니다. 화면 아래쪽에는
사용 가능한 모든 작업이 포함된 입력 범례가 표시됩니다.

## 샘플 화면

![Text Description automatically generated](./media/image3.png)

| 액션                        |  게임 패드                              |
|-----------------------------|----------------------------------------|
| 사용자 로그인               |  메뉴 버튼/\<Tab\> 키                   |
| 현재 필터의 UI 새로 고침    |  A 버튼/F5 키                           |
| 조회한 소셜 그룹 변경  |  LB 및 RB 어깨 버튼/왼쪽 또는 오른쪽 화살표 키                              |
| 끝내기                      |  보기 버튼/\<Esc\> 키                   |

# 구현 참고 사항

소셜 관리자 API와 직접 인터페이스하는 코드는
SocialManagerIntegration.cpp 파일에 캡슐화됩니다.

# 개인정보처리방침

샘플을 컴파일하고 실행하는 경우 샘플 사용량을 추적할 수 있도록 샘플 실행
파일의 파일 이름이 Microsoft에 전송됩니다. 이 데이터 수집을
옵트아웃하려면 \"샘플 사용량 원격 분석\"으로 레이블이 지정된
Main.cpp에서 코드 블록을 제거할 수 있습니다.

Microsoft의 개인정보 정책에 대한 자세한 내용은 [Microsoft 개인정보
처리방침](https://privacy.microsoft.com/en-us/privacystatement/)을
참조하세요.

# 업데이트 기록

**업데이트 날짜:** *2021년 7월*

**초기 릴리스:** *2019년 9월*
