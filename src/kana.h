/***************************************************************************
 *   Copyright (C) 2004 by Mathias Homann                                  *
 *   Mathias.Homann@eregion.de                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef _KANA_H_
#define _KANA_H_

typedef struct {
  const char    * pRomaji;
  const char    * pHiragana;
  const char    * pKatakana;
} transInfo;



// roumaji -> kana, all chars. 0-45 is basic, 46-73 is extended, 74-103end is compound.

static transInfo kanatable[] =
{
"a", "あ", "ア",
"i", "い", "イ",
"u", "う", "ウ",
"e", "え", "エ",
"o", "お", "オ",
"ka", "か", "カ",
"ki", "き", "キ",
"ku", "く", "ク",
"ke", "け", "ケ",
"ko", "こ", "コ",
"sa", "さ", "サ",
"shi", "し", "シ",
"su", "す", "ス",
"se", "せ", "セ",
"so", "そ", "ソ",
"ta", "た", "タ",
"chi", "ち", "チ",
"tsu", "つ", "ツ",
"te", "て", "テ",
"to", "と", "ト",
"na", "な", "ナ",
"ni", "に", "ニ",
"nu", "ぬ", "ヌ",
"ne", "ね", "ネ",
"no", "の", "ノ",
"ha", "は", "ハ",
"hi", "ひ", "ヒ",
"fu", "ふ", "フ",
"he", "へ", "ヘ",
"ho", "ほ", "ホ",
"ma", "ま", "マ",
"mi", "み", "ミ",
"mu", "む", "ム",
"me", "め", "メ",
"mo", "も", "モ",
"ya", "や", "ヤ",
"yu", "ゆ", "ユ",
"yo", "よ", "ヨ",
"ra", "ら", "ラ",
"ri", "り", "リ",
"ru", "る", "ル",
"re", "れ", "レ",
"ro", "ろ", "ロ",
"wa", "わ", "ワ",
"wo", "を", "ヲ",
"n", "ん", "ン",
"ga", "が", "ガ",
"gi", "ぎ", "ギ",
"gu", "ぐ", "グ",
"ge", "げ", "ゲ",
"go", "ご", "ゴ",
"za", "ざ", "ザ",
"ji", "じ", "ジ",
"zu", "ず", "ズ",
"ze", "ぜ", "ゼ",
"zo", "ぞ", "ゾ",
"da", "だ", "ダ",
"ji", "ぢ", "ヂ",
"zu", "づ", "ズ",
"de", "で", "デ",
"do", "ど", "ド",
"ba", "ば", "バ",
"bi", "び", "ビ",
"bu", "ぶ", "ブ",
"be", "べ", "ベ",
"bo", "ぼ", "ボ",
"pa", "ぱ", "パ",
"pi", "ぴ", "ピ",
"pu", "ぷ", "プ",
"pe", "ぺ", "ペ",
"po", "ぽ", "ポ",
"kya", "きゃ", "キャ",
"kyu", "きゅ", "キュ",
"kyo", "きょ", "キョ",
"sha", "しゃ", "シャ",
"shu", "しゅ", "シュ",
"sho", "しょ", "ショ",
"cha", "ちゃ", "チャ",
"chu", "ちゅ", "チュ",
"cho", "ちょ", "チョ",
"nya", "にゃ", "ニャ",
"nyu", "にゅ", "ニュ",
"nyo", "にょ", "ニョ",
"hya", "ひゃ", "ヒャ",
"hyu", "ひゅ", "ヒュ",
"hyo", "ひょ", "ヒョ",
"mya", "みゃ", "ミャ",
"myu", "みゅ", "ミュ",
"myo", "みょ", "ミョ",
"rya", "りゃ", "リャ",
"ryu", "りゅ", "リュ",
"ryo", "りょ", "リョ",
"gya", "ぎゃ", "ギャ",
"gyu", "ぎゅ", "ギュ",
"gyo", "ぎょ", "ギョ",
"ja", "じゃ", "ジャ",
"ju", "じゅ", "ジュ",
"jo", "じょ", "ジョ",
"bya", "びゃ", "ビャ",
"byu", "びゅ", "ビュ",
"byo", "びょ", "ビョ",
"pya", "ぴゃ", "ピャ",
"pyu", "ぴゅ", "ピュ",
"pyo", "ぴょ", "ピョ"
};

#endif
