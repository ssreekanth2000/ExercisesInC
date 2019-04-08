#include <glib.h>
#include <stdio.h>
#include <stdlib.h>



void print_num(gchar *word, GHashTable *dictionary_of_words){
  printf("%s:  %ld\n", word, (gint32)g_hash_table_lookup(dictionary_of_words, word));
}


void frequency_histogram(FILE *input_file, gchar *temp, gchar *valid_chars,gchar substitute_char, GHashTable *dictionary){
  while(fscanf(input_file, "%1023s",temp)==1){
    g_strcanon(temp, valid_chars, substitute_char);
    if(g_strcmp0(temp," ")!=0 && g_strcmp0(temp, "") != 0){
      if(g_hash_table_contains(dictionary, temp)){
        g_hash_table_replace(
          dictionary, g_strdup(temp),
          (gpointer)(((gint64)g_hash_table_lookup(dictionary, temp))+1));


      }
     else {
       g_hash_table_insert(dictionary, g_strdup(temp),(gpointer)1);
     }


    }
  }
}

gint compare_numbers(gchar *word1, gchar *word2, GHashTable *dictionary) {
  return ((gint64)g_hash_table_lookup(dictionary, word1)) -
         ((gint64)g_hash_table_lookup(dictionary, word2));
}

int main(int argc, char **argv) {
  if (argc < 2) {
    puts("no file");
    exit(1);
  }

  FILE *text = fopen(argv[1], "r");
  if (!text) {
    printf("file not valid.");
    exit(1);
  }

  gchar buffer[1024];
  gchar valid[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  gchar substitute_char = 0;
  GHashTable *dictionary = g_hash_table_new(g_str_hash, g_str_equal);

  frequency_histogram(text, buffer, valid, substitute_char, dictionary);

  g_list_foreach(g_list_sort_with_data(g_hash_table_get_keys(dictionary),
                                       (GCompareFunc)compare_numbers, dictionary),
                 (GFunc)print_num, dictionary);

  fclose(text);
  exit(0);
}
