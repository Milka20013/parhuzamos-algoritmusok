# Párhuzamos-algoritmusok
## Beadandó feladat kiírás
### Posix
Adott szó/szavak keresése egy szövegben, hasonlóan mint ahogy a weboldalakon, szövegszerkesztőkben a CTRL + F hatására kereshetünk. A program több szálon keresné meg egy adott szövegben az összes előfordulását a keresendő szavaknak, ennek indexeit visszaadva.
### OpenMP
Anagramma program készítése. A program egy adott karakter sorozatról eldönti, hogy milyen értelmes szavak rakhatóak ki egy ugyancsak adott szótárban lévő szavak közül. (pl. amla -> alma, amla -> ma ... minden értelmes szó). Ennek az algoritmusnak az alap futási idejét még a párhuzamosítás előtt optimalizálnám (ahelyett az algoritmus helyett ami először eszünkbe juthat), majd párhuzamosítanám a keresést több szállal.
### "Bármi más"
Szövegek összeadása/kivonása, szorzása/osztása (pl. (alma + körte)* anya/apa ). Erre a rendszerem az lenne, hogy a betűkhöz számokat rendelek, mintha egy számrendszerben lennének. Lenne egy nulla elem (@), utána pedig abc rendben lennének a betűk számozva (a->1, á->2...), "kettős" betűk (gy,ty) kettő darab külön betűként lenne kezelve, illetve ezeket nyelvtől függetlenül határozná meg egy algoritmus, egy adott szótár által.
A @-kat tartalmazó betűket nem tekintjük értelmes szavaknak, az első helyen lévő @-kat elhagyjuk. A magyar abc-ben  például 36 különböző betű van ilyen szabályokkal, plussz a @, tehát 37-es számrendszerben képzelhetőek el a szavak.
A szavakat íly módon a pozitív egész számok halmazára képezhetjük le, abból nem léphetünk ki, tehát negatív és nem egész "szavak" nem értelmezhetőek. Mivel a túl hosszú szavak túl nagy számokat is eredményeznének, így a szavakat közvetlenül nem váltjuk át számokká, a műveleteket külön rendszerrel végezzük el.
Az egésznek az lenne a lényege, hogy meghatározzuk ezen szabályokkal, hogy mely szavak milyen művelettel eredményeznek értelmes szavakat. pl. ha minden értelmes szót páronként összeadunk/összeszorzunk, akkor lesz-e értelmes szó eredményként. Ennek keresését párhuzamosítanám egy C#-ban megírt programban.
### +1
Az előző feladathoz kiegészítésként lazíthatunk a feltételen és olyan szavakat is kereshetünk, amiken műveleteket végezve olyan karakterláncot kapunk, melyből kirakható ugyanolyan hosszú értelmes szó (tehát felhasználható az OpenMP-s feladat).
### +2
Plussz kiegészítésként felhasználható a szavak összeadása kódoláshoz. Kulcsként megadható egy szó/karakter hasonló formában mint az (alma + körte)* anya/apa, majd ennek az eredménye a kulcs, amivel elvégezhetünk egy szimmetrikus kódolást. Az így kapott szöveget a kulccsal együtt elküldhetjük, mert a kulcsot nem feltétlenül fogja érteni más, aki nem tudja a szavakkal való műveleteket elvégezni.
Gondolkoztam az első feladattal való összekötésben is, de arra nem találtam ki egy jó ötletet.
