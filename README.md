# Párhuzamos-algoritmusok
## Beadandó feladat kiírás
### Posix
Adott szöveges kifejezés keresése egy szövegben, hasonlóan mint ahogy a weboldalakon, szövegszerkesztőkben a CTRL + F hatására kereshetünk. A program több szálon keresné meg egy adott szövegben az összes előfordulását a keresendő szöveges kifejezésnek, ennek indexeit visszaadva.
Kétféle algoritmus lesz összehasonlítva: naív és Knuth–Morris–Pratt algoritmusok.
### OpenMP
Anagramma program készítése. A program egy adott karakter sorozatról eldönti, hogy milyen értelmes szavak rakhatóak ki egy ugyancsak adott szótárban lévő szavak közül. (pl. amla -> alma, amla -> ma ... minden értelmes szó).
Kétféle algoritmus lesz összehasonlítva:
- "tartalmaz stratégia" : ha egy szó tartalmazza a betűt kivesszük a betűt a szóból, majd a következő betűt vizsgáljuk a már levágott szóban.
- "számláló stratégia": a szövegeket egész tömbökké alakítjuk, és helyiérték szerint növeljük/csökkentjük a tömb értékeket, majd eszerint mérlegelünk (az algoritmus még csak elméletben van meg, így csak a lényeget említettem).
### C# multithreading / tasks
Szövegek összeadása/kivonása, szorzása/osztása (pl. (alma + körte)* anya/apa ). Erre a rendszerem az lenne, hogy a betűkhöz számokat rendelek, mintha egy számrendszerben lennének. Lenne egy nulla elem (@), utána pedig abc rendben lennének a betűk számozva (a->1, á->2...), "kettős" betűk (gy,ty) kettő darab külön betűként lenne kezelve, illetve ezeket nyelvtől függetlenül határozná meg egy algoritmus, egy adott szótár által.
A @-kat tartalmazó betűket nem tekintjük értelmes szavaknak, az első helyen lévő @-kat elhagyjuk. A magyar abc-ben  például 36 különböző betű van ilyen szabályokkal, plussz a @, tehát 37-es számrendszerben képzelhetőek el a szavak.
A szavakat íly módon a pozitív egész számok halmazára képezhetjük le, abból nem léphetünk ki, tehát negatív és nem egész "szavak" nem értelmezhetőek.
Az egésznek az lenne a lényege, hogy meghatározzuk ezen szabályokkal, hogy mely szavak milyen művelettel eredményeznek értelmes szavakat. pl. ha minden értelmes szót páronként összeadunk/összeszorzunk, akkor lesz-e értelmes szó eredményként. Ennek keresését párhuzamosítanám egy C#-ban megírt programban.
Matematikai leírás:
- Legyen adott egy A abc (halmaz), mely csak 1 hosszú betűket tartalmaz, a betűk sorrendje adott, a halmaz hossza pedig n. Az abc mindig tartalmazza a '@' speciális karaktert.
- Vegyük az n alapú számrendszert, illetve egy f : A->Z/Z- (pozitív egész számok)ba képző függvényt, melyre f(x) = i, ahol i a betű A-ban elfoglalt helyének sorszáma.
- Legyen W az összes A-beli betűből előállítható szavak halmaza (egy betűt többször is használhatunk). Legyen g : W->Z/Z- függvény, melyre g(w) = (f(w(j)))*n^k +
(f(w(j + 1)))*n^(k-1) + ... + (f(w(k)))*n^0, ahol k a szó hossza, j fut 1-től k-ig.
- A műveleteket ilyen formán egész számokkal végezhetjük.
### +1
Az előző feladathoz kiegészítésként lazíthatunk a feltételen és olyan szavakat is kereshetünk, amiken műveleteket végezve olyan karakterláncot kapunk, melyből kirakható ugyanolyan hosszú értelmes szó (tehát felhasználható az OpenMP-s feladat).
### +2
Plussz kiegészítésként felhasználható a szavak összeadása kódoláshoz. Kulcsként megadható egy szó/karakter hasonló formában mint az (alma + körte)* anya/apa, majd ennek az eredménye a kulcs, amivel elvégezhetünk egy szimmetrikus kódolást. Az így kapott szöveget a kulccsal együtt elküldhetjük, mert a kulcsot nem feltétlenül fogja érteni más, aki nem tudja a szavakkal való műveleteket elvégezni.
