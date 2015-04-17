
@begin
include "encipher.h"
@end

void encipher_file(int argc,char **argv)
{/*{{{*/
  string_s text;
  text.init();

  // - read source text file -
  if (!text.load_text_file(argv[1]))
  {
    fprintf(stderr,"%s: Cannot read from file \"%s\"\n",argv[0],argv[1]);

    text.clear();
    exit(2);
  }

  char *text_buff = text.data;
  unsigned text_length = text.size - 1;

  // - denote if source text is cipher -
  bool source_is_cipher = false;

  cipher_s cipher;
  cipher.init();

  // - test if text is cipher -
  if (cipher.is_cipher(text_length,text_buff))
  {
    // - remove cipher magic number -
    text_buff += c_cm_length;
    text_length -= c_cm_length;

    // - mark source text as cipher -
    source_is_cipher = true;
  }

  cipher.create(c_ck_length,(char *)c_ck_value);
  cipher.process(text_length,text_buff);
  cipher.clear();

  // - open target file -
  FILE *f = fopen(argv[2],"w");
  if (f == NULL)
  {
    fprintf(stderr,"%s: Cannot open file \"%s\"\n",argv[0],argv[2]);

    text.clear();
    exit(2);
  }

  bool write_err = false;

  // - if source text is cipher -
  if (!source_is_cipher)
  {
    // - write magic word to target file -
    if (fwrite(c_cm_value,c_cm_length,1,f) != 1)
    {
      write_err = true;
    }
  }

  // - write data to target file -
  if (fwrite(text_buff,text_length,1,f) != 1)
  {
    write_err = true;
  }

  if (write_err)
  {
    fprintf(stderr,"%s: Cannot write to file \"%s\"\n",argv[0],argv[2]);

    fclose(f);
    text.clear();
    exit(2);
  }

  fclose(f);
  text.clear();
}/*}}}*/

int main(int argc,char **argv)
{/*{{{*/

  if (argc < 3)
  {
    fprintf(stderr,"%s: Expected names of source and target files\n",argv[0]);

    exit(22);
  }

  // - encipher file -
  encipher_file(argc,argv);

}/*}}}*/

