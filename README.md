# simple-calculator

Tlooks Simple Calculatorはとても簡単な計算機ですが、通常の計算機能は持ち合わせていません。主に、最大公約数や約分など、個人的に頻繁に使うものを落とし込んだものになります。

実行ファイルを実行することでも起動しますが、コマンド引数を与えることでも起動します。

# 実装されている機能

* <code>-s , sum , --sum</code>：引数の合計値を計算します。
* <code>-d , divisor , --divisor</code>：引数の最大公約数を計算します。
* <code>-c , coprimality , --coprimality</code>:入力された引数が互いに素かどうかを表示します。
* <code>-r , reduction , --reduction</code>:入力された分数（１つ目の引数を分子、２つ目の引数を分母と扱います）を約分します。
* <code>-a , average , --average</code>:引数の平均を計算します。
* <code>-p , pow , --pow</code>:引数を累乗します。
* <code>-m , multiple</code>:引数の最小公倍数を計算します。

# 今後のアップデートで追加されるかもしれない機能

* <code>-l , log</code>:対数を計算します。

# 既知の問題

現在はなし

# 必要要件

Tloosk Simple Calculatorは必要な要件として、G++またはClang++をコンパイラとして要求する。Visual C++ではビルドできない。

# インストール方法

## Mac/Linux/BSD

ダウンロードしたソースコードでmakeコマンド実行

## Windows

ダウンロードしたアーカイブを解凍・展開して<code>main.cpp</code>があるディレクトリで

<code>win_install.bat</code>を実行する。
