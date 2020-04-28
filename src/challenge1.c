/*
The Greplin Programming Challenge

 Level 1

 ----------------------------------------

 Embedded in this block of text is the password for level 2.
 The password is the longest substring that is the same in reverse.

 As an example, if the input was "I like racecars that go fast"
 the password would be "racecar"
*/

#include <string.h>
#include <stdio.h>

const char g_cad[] = 
"Fourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinz"
"LibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtci"
"vilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeare"
"qmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrest"
"ingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandprope"
"rthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowth"
"isgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwe"
"rtoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverfo"
"rgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhicht"
"heywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattd"
"afskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhic"
"htheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothave"
"diedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeop"
"lebythepeopleforthepeopleshallnotperishfromtheearth";

int is_str_palindrome(const char * init, const char * end)
{
    while ((*init == *end) && (init <= end)) {
        init++;
        end--;
    }

    return (init >= end);
}

int main(void)
{
    int l = strlen(g_cad);
    int i, j, ibest, lbest;

    ibest = lbest = 0;

    for (j = l - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (is_str_palindrome(g_cad+i, g_cad+j))
                if (j-i > lbest) {
                    ibest = i;
                    lbest = j-i+1;
                }
        }
    }

    printf("Solution to challenge 1 is '%.*s'\n", lbest, g_cad+ibest);
}

