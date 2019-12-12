def main():
    word_string = read_file('test.txt')
    list_word = split_string(word_string, ' | ')
    write_to_file('words.txt', list_word)


def read_file(filename):
    with open(filename, 'r') as fr:
        words = fr.read()
    return words


def split_string(string, delimiter):
    word_list = string.split(delimiter)
    return word_list


def write_to_file(filename, words):
    with open(filename, 'w') as fw:
        for word in words:
            fw.write(word + '\n')


if __name__ == "__main__":
    main()
