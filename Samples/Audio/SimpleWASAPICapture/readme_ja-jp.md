# 簡単な WASAPI キャプチャのサンプル

*このサンプルは、Microsoft ゲーム開発キットのプレビュー (2019 年 11 月)
に対応しています。*

# 説明

このサンプルでは、Xbox One で WASAPI
を使用して音声をキャプチャする方法を実演します。

![Sample Screenshot](./media/image1.png)

# サンプルのビルド

Xbox One の devkit を使用している場合は、アクティブなソリューション
プラットフォームを Gaming.Xbox.XboxOne.x64 に設定します。

Project Scarlett を使用している場合は、アクティブなソリューション
プラットフォームを Gaming.Xbox.Scarlett.x64 に設定します。

*詳細については、GDK
ドキュメント*の「サンプルの実行」を*参照してください*。

# サンプルの使用

コントローラーでキャプチャ デバイスを選びます。
このサンプルでは、自動的に既定のオーディオ レンダラを使用します。
**キャプチャとレンダリングの間でサンプル
レートの変換は行われないので、サンプル
レートが一致しない限り正しく再生されないことに注意してください。**

# 実装に関する注意事項

このサンプルでは、WASAPI
を使用して音声をキャプチャする方法を実演します。
キャプチャしたサンプルはリング
バッファに置かれ、それからレンダリングされます。
この例では、レンダラとキャプチャで共有する WASAPI
インスタンスも使用します。 WASAPI の高度な使用方法は「[Windows WASAPI
サンプル](https://code.msdn.microsoft.com/windowsapps/Windows-Audio-Session-22dcab6b)」をご覧ください。

# 更新履歴

最初のリリース: 2019 年 5 月

# プライバシーに関する声明

サンプルをコンパイルして実行すると、サンプルの使用状況を追跡するため、サンプル実行可能ファイルのファイル名が
Microsoft に送信されます。このデータ収集を無効にするには、「Sample Usage
Telemetry」とラベル付けされた Main.cpp
内のコードのブロックを削除します。

Microsoft のプライバシー方針の詳細については、「[Microsoft
プライバシーに関する声明](https://privacy.microsoft.com/en-us/privacystatement/)」を参照してください。