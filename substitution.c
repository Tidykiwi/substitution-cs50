#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> // location of "atoi"
#include <string.h> // location of "strlen"
#include <ctype.h>  // location of "isalpha" "islower" "isupper" "isdigit"

int main(int argc, string argv[])

{
    int total = 0;
    int asc_a;
    int asc_aa;

    if (argc == 2)
    {

        int sl = strlen(argv[1]);

        if (sl != 26)  // checks to see if the use input is the right length
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }

        for (int x = 0; x < sl; x++)
        {
            if (isalpha(argv[1][x]) == 0)  //checks user input to see if any character is not alphabetic
            {
                printf("Key must contain letters only\n");
                return 1;
            }
            else if (isalpha(argv[1][x]) != 0) // checks user input for repeated characters
            {
                char a = argv[1][x];  // isolates each char of string one by one then...
                asc_a = (int) a;  // ...then re-casts it as its ascii value

                for (int y = 0; y < sl; y++) // a nested loop starts that...
                {
                    char aa = argv[1][y];  // ...that isolates each char and...
                    asc_aa = (int) aa;    // ...and re-casts it as its ascii value

                    if (asc_aa == asc_a || asc_aa == (asc_a + 32) || asc_aa == (asc_a - 32)) // compares the ascii values and...
                    {
                        total++;  // ...and adds 1 to the counter if (a == a/ a == A / A == a / A == A)
                    }
                }

            }


        }

        if (total > 26) // if total is more than 26 then there is a repeat character - either lowercase or uppercase
        {
            printf("Key must not contain repeated characters\n");
            return 1;
        }

        string text = get_string("plaintext: ");

        printf("ciphertext: ");

        for (int x = 0; text[x] != '\0'; x++)
        {
            if (isalpha(text[x]) == 0)  // identifies non-alphabetic chars and...
            {
                printf("%c", text[x]);  // ...and leaves them unchanged
            }
            else if (islower(text[x]) != 0)  // identifies lower case chars
            {
                int ai = (text[x] - 97);  // using ascii values converts the LC char to an alphabetical index (AI) value
                if (islower(argv[1][ai]) != 0)  // looks to see if the char at the corresponding AI position in the key is also LC
                {
                    printf("%c", argv[1][ai]);  // if yes PERFECT we can directly print the char at the AI position in the key
                }
                else if (islower(argv[1][ai]) == 0)  // if the char at the AI position is not LC (i.e. UC) then...
                {
                    printf("%c", argv[1][ai] + 32);  // ...then 32 is added to give the char at the AI position the LC ascii value
                }

            }
            else if (isupper(text[x]) != 0)  // identifies upper case chars
            {
                int AI = (text[x] - 65);  // using ascii values converts the UC char to an alphabetical index (AI) value
                if (isupper(argv[1][AI]) != 0)  // looks to see if the char at the corresponding AI position in the key is also UC
                {
                    printf("%c", argv[1][AI]);  // if yes PERFECT we can directly print the char at the AI position in the key
                }
                else if (isupper(argv[1][AI]) == 0)  // if the char at the AI position is not UC (i.e. LC) then...
                {
                    printf("%c", argv[1][AI] - 32);  // ...then 32 is subtracted to give the char at the AI position the UC ascii value
                }

            }

        }

        printf("\n");

    }

    else

    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

}
