#include <glib.h>
#include <stdio.h>
#include <stdlib.h>



void print_num(gchar *word, GHashTable *directory){
  printf("%s:  %ld\n", word, (gint32)g_hash_table_lookup(dictionary, word));
}

void frequency_histogram(FILE *input_file, gchar *buffer, gchar *valid_chars,gchar substitute_char, GHashTable *dictionary){
  while(fscanf(input_file, "%1023s",buffer)==1){
    g_strcanon(buffer, valid_chars, substitute_char);
    if(g_strcmp0(buffer," ")!=0 && g_strcmp0(buffer, "") != 0){
      if(g_hash_table_contains(dictionary, buffer)){
        g_hash_table_replace(
          dictionary, g_strdup(buffer),
          (gpointer)(((gint64)g_hash_table_lookup(dictionary, buffer))+1));


      }
     else {
       g_hash_table_insert(dictionary, g_strdup(buffer),(gpointer)1);
     }


    }
  }
}


int main(int argc, char **argv) {
  if (argc < 2) {
    puts("Must provide a file name.");
    exit(1);
  }

  FILE *text = fopen(argv[1], "r");
  if (!text) {
    printf("Invalid file.");
    exit(1);
  }

  gchar buffer[1024];
  gchar valid_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  gchar substitute_char = 0;
  GHashTable *dictionary = g_hash_table_new(g_str_hash, g_str_equal);

  word_histogram(text, buffer, valid_chars, substitute_char, dictionary);

  g_list_foreach(g_list_sort_with_data(g_hash_table_get_keys(dictionary),
                                       (GCompareFunc)compare_keys, dictionary),
                 (GFunc)print_entry, dictionary);

  fclose(text);
  exit(0);
}
