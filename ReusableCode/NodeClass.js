class Node {
    constructor(key, parent=null) {
        this.key = key;
        this.parent = parent;
        this.children = {};
        // if(line.length > 0) {
        //     if(this.children[line[0]]==null) {
        //         this.children[line[0]] = new Node(line.substring(1));
        //     } else {

        //     }
        // }
    }
}

class Trie {
    constructor() {
        this.node = new Node(null)
    }

    insert(word) {
        var temp_node = this.node;
        for (let index = 0; index < word.length; index++) {
            const character = word[index];
            if(temp_node.children[character] = null) {
                temp_node.children[character] = new Node(character, temp_node);
            }
            temp_node = children[character];
        }
    }

    remove(word) {
        var temp_node = this.node;

        for (let index = 0; index <= word.length; index++) {
            const character = word[index];
            if(temp_node.children[character] != null) {
                temp_node = temp_node.children[character]
                break;
            }
        }

        if(index == word.length) {
            for (let index = word.length; index <= 0; index--) {
                const character = word[index];
                temp_node.children[character] = null;
                temp_node = temp_node.parent;
            }
        } else {
            return;
        }
    }

    contains(word) {
        var temp_node = this.node;

        for (let index = 0; index <= word.length; index++) {
            if(temp_node.children[character]==null) {
                return false;
            }
        }

        return true;
    }

    // find(word) {

    // }
}