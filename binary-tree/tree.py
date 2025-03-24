class Node:
    def __init__(self):
        self.data  : dict = {}
        self.end : bool = False

    def is_word(self) -> bool:
        return self.end

    def add_word(self):
        self.end = True

    def get_word(self, c) -> 'Node':
        return self.data.get(c, None)

    def word_exists(self, c) -> bool:
        return c in self.data

    def remove_word(self):
        self.end = False


class Trie:
    def __init__(self):
        self.root = Node()


    def insert_word(self, word):
        current = self.root
        for c in word:
            if not current.word_exists(c):
                current.data[c] = Node()
            current = current.get_word(c)
        current.add_word()

    def search_word(self, word) -> bool:
        current = self.root
        for c in word:
            if not current.word_exists(c):
                return False
            current = current.get_word(c)
        return current.is_word()


    def delete_word(self, word) -> bool:
        current = self.root
        for c in word:
            if not current.word_exists(c):
                return False
            current = current.get_word(c)
        current.remove_word()
        return True
