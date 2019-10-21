#include <stdio.h>;
#include <unistd.h>;
#include <string.h>;
#include <openssl/des.h>;
char *Encrypt( char *Key, char *Msg, int size)
{
static char* Res; int
n=0; DES_cblock
Key2;
DES_key_schedule schedule;
Res = ( char * ) malloc( size );
/* Prepare the key for use with DES_cfb64_encrypt */
memcpy( Key2, Key,8);
DES_set_odd_parity( &amp;Key2 );
DES_set_key_checked( &amp;Key2, &amp;schedule );
/* Encryption occurs here */
DES_cfb64_encrypt( ( unsigned char * ) Msg, ( unsigned char * ) Res,size, &amp;schedule,
&amp;Key2, &amp;n, DES_ENCRYPT );
return (Res);
}
char *Decrypt( char *Key, char *Msg, int size)
{
static char* Res; int
n=0; DES_cblock
Key2;
DES_key_schedule schedule;
Res = ( char * ) malloc( size );
/* Prepare the key for use with DES_cfb64_encrypt */
memcpy( Key2, Key,8);
DES_set_odd_parity( &amp;Key2 );
DES_set_key_checked( &amp;Key2, &amp;schedule );
/* Decryption occurs here */
DES_cfb64_encrypt( ( unsigned char * ) Msg, ( unsigned char * ) Res,size, &amp;schedule,
&amp;Key2, &amp;n, DES_DECRYPT );
return (Res);
}
int main()
{
char key[]=&quot;BENEDICT&quot;;
char plaintext[]=&quot;ENJOYCNS&quot;;
char *decrypted; char *encrypted;
encrypted=malloc(sizeof(plaintext));
decrypted=malloc(sizeof(plaintext));
printf(&quot;\nPlaintext\t\t\t : %s&quot;,plaintext);
printf(&quot;\nPlaintext in Hex Code \t\t : %X&quot;,plaintext);
printf(&quot;\nKey in Hex Code \t\t : %X&quot;,key);
memcpy(encrypted,Encrypt(key,plaintext,sizeof(plaintext)), sizeof(plaintext));
printf(&quot;\nEncrypted Text\t\t\t : %s&quot;,encrypted);
memcpy(decrypted,Decrypt(key,encrypted,sizeof(plaintext)), sizeof(plaintext));
printf(&quot;\nDecrypted Text\t\t\t : %s&quot;,decrypted);
printf(&quot;\nDecrypted Text in Hex Code \t : %X \n&quot;,decrypted);
return (0);
}
