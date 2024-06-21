# 사용자 지정 해상도 샘플

*이 샘플은 Microsoft 게임 개발 키트와 호환됩니다(2022년 10월). Xbox Series(Scarlett) 하드웨어에서만 실행되도록 만들어졌습니다.*

## 설명

콘솔 게임은 일반적으로 특정 해상도로 렌더링되며 거의 항상 16:9 가로 세로 비율로 렌더링됩니다. xCloud 서비스에서 게임을 스트리밍할 경우 대상 장치가 해상도나 가로 세로 비율과 항상 일치하지는 않습니다. 현재 게임은 장치에 맞게 문자 또는 기둥 상자로 렌더링됩니다. 일부 `XGameStreaming` API를 사용하면 게임에 스트리밍 장치 크기를 알릴 수 있으므로 해상도를 모두 조정하고 xCloud에 디스플레이에 더 적합한 해상도로 스트리밍하도록 지시할 수 있습니다. 이 샘플에서는 장치 크기를 이해하고 렌더링 및 스트리밍 해상도를 조정하기 위해 이러한 API를 사용하는 방법을 보여 줍니다.

![샘플 스크린샷](./media/rId20.png) ![샘플 스크린샷](./media/rId23.png)

## 샘플 빌드

샘플은 `Gaming.Xbox.XboxOne.x64` 및 `Gaming.Xbox.Scarlett.x64` 플랫폼을 모두 대상으로 할 수 있지만 Xbox Series 하드웨어를 활용하는 스트리밍 시나리오로 인해 Xbox Series(Scarlett) 하드웨어에서만 실행되도록 만들어졌습니다.

## 샘플 사용

이 샘플에서는 다음 컨트롤을 사용합니다.

| 동작 | Gamepad |
|---|---|
| 해상도 메뉴 브링업 | 메뉴 |
| 카메라 회전/확대/축소/조정 | 왼쪽 스틱/오른쪽 스틱 |
| Xbox 로고 숨기기 | X |
| 샘플 종료 | 보기 |

샘플은 [웹](https://www.xbox.com/play/dev-tools) 또는 [Windows 스트리밍 콘텐츠 테스트](https://apps.microsoft.com/store/detail/xbox-game-streaming-test-app/9NZBPVPNLDGM) 앱과 같은 스트리밍 클라이언트로 스트리밍하기 위한 것입니다. 이
[문서](https://learn.microsoft.com/en-us/gaming/gdk/_content/gc/system/overviews/game-streaming/game-streaming-setup-xbox-developer-kit)를 참조하여
devkit에서 클라이언트로 스트리밍을 구성하는 방법을 알아보세요.

스트리밍이 완료되면 샘플은 스트리밍 클라이언트 디스플레이의 현재 크기에 맞게 조정됩니다. 클라이언트 크기를 조정하면 새 크기와 일치하도록 샘플 해상도도 조정됩니다. 이 작업을 제대로 수행하고 있는지는 Xbox 로고(표시되는 경우)와 장면 중간에 있는 구가 디스플레이의 가로 세로 비율에 관계없이 항상 완벽하게 둥글다는 것으로 확인할 수 있습니다.

샘플을 미리 설정된 해상도 목록 중 하나로 설정할 수 있도록 메뉴를 가져올 수 있습니다. 해당 단추를 선택하여 스트리밍 인스턴스에 해당 해상도로 스트리밍하도록 별도로 지시할 수 있습니다. 이는 장치가 스트리밍하는 것과 독립적으로 해상도를 변경하는 효과를 보여 주는 고안된 분리입니다. 이는 크기를 조정하면 동시에 발생합니다.

스트리밍이 지원할 수 있는 크기와 픽셀 수에 제한이 있으므로(예: 풀 4k 해상도로 스트리밍할 수 없음) 메뉴의 일부 해상도는 의도적으로 오류를 발생시킵니다. 시간이 지남에 따라 변경될 수 있습니다.

[사용자 지정 해상도를 사용한 테스트](https://learn.microsoft.com/en-us/gaming/gdk/_content/gc/system/overviews/game-streaming/game-streaming-testing-custom-resolution)에 관한 자세한 내용은 문서에서 확인할 수 있습니다.

## 구현 참고 사항

이 샘플은 동적 해상도 샘플의 장면과 일부 구조 및 코드를 다시 사용합니다. 그래픽 모범 사례를 보여주기 위한 것이 아니므로 변경 가능하지만 정적인 해상도를 지원하는 데 필요가 없는 코드가 있을 수 있습니다. 이는 시간이 지남에 따라 정리될 것입니다. 핵심은 메뉴에서 선택할 때 크기 조정 시 렌더링 해상도를 조정할 수 있다는 것입니다.

## 알려진 문제

이 샘플에는 2022년 10월 GDK 및 복구 또는 최신 버전이 필요합니다.

스트리밍 시나리오에서 해당 하드웨어를 사용하지 않으므로 이 샘플은 Xbox One 하드웨어에서 실행되지 않습니다.

일부 UI가 특정 해상도에서 잘립니다. 지능형 UI 재구성 및 크기 조정은 이 샘플의 범위에 포함되지 않습니다.

## 업데이트 기록

**2022년 10월:** 초기 릴리스

## 개인정보처리방침

샘플을 컴파일하고 실행하는 경우 샘플 사용량을 추적할 수 있도록 샘플 실행 파일의 파일 이름이 Microsoft에 전송됩니다. 이 데이터 수집을 옵트아웃하려면 Main.cpp에서 "샘플 사용량 원격 분석"이라는 레이블이 지정된 코드 블록을 제거할 수 있습니다.

일반적인 Microsoft의 개인 정보 정책에 대한 자세한 내용은 [Microsoft 개인정보처리방침](https://privacy.microsoft.com/en-us/privacystatement/)을 참조하세요.

