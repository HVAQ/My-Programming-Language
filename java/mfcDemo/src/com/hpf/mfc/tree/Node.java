package com.hpf.mfc.tree;

import com.hpf.mfc.global.InterfaceTree;

public abstract class Node 
    implements InterfaceTree {
    private String name;
    private String id;

    public Node(String name, String id) {
        if (!isNum(id)) {
            this.id = isNum(name) ? name : id;
        }
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getId() {
        return this.id;
    }

    public boolean isSame(Node node) {
        boolean judge = (this.name.equals(node.getName()) &&
                this.id.equals(node.getId())) ? true : false;
        return judge;
    }

    public boolean isNum(String str) {
        boolean judge = true;
        for (int index = 0; index < str.length(); index++) {
            judge = Character.isDigit(str.charAt(index)) ? true : false;
            if (judge == false) {
                break;
            }
        }
        return judge;
    }
}
