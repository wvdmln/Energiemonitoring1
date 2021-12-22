// Deze header file wordt met het include statement vooraan in het hoofdprogramma geladen
// Voor Arduino lijkt het dus alsof .h en .cpp 1 geheel vormen

// voorbeelden van string variabelen
// deze strings worden van uit het hoofdprogramma geprint
// door te verwijzen naar de variabelen tekstSom, tekstVerschil,...
// hierdoor wordt het hoofdprogramma overzichtelijker

#define tekstSom "De som van de getallen is  "
#define tekstVerschil "Het verschil van de getallen is "
#define tekstProduct "Het product van de getallen is "
#define tekstWortelKwadraatsom "Pythagoras >>  "

// voorbeelen van berekeningen
// de 2 getallen worden van uit het hoofdprogramma doorgestuurd
// het resultaat keert terug naar het hoofdprogramma
// ook op deze manier blijft het hoofdprogramma overzichtelijk

int add(int x, int y)
{
    int som = x + y;
    return som;
}

int sub(int x, int y)
{
    int verschil = (x - y);
    return verschil;
}

int mul(int x, int y)
{
    int product(x * y);
    return product;
}

float pythagoras(int x, int y)
{
    float wortelmacht = sqrt(sq(x) + sq(y));
    return wortelmacht;
}