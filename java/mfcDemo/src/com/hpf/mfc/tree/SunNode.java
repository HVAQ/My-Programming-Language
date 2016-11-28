package com.hpf.mfc.tree;

import com.hpf.mfc.tree.Node;

public abstract class SunNode 
    extends Node {
    private SunNode right;
    private SunNode left;

    public SunNode(String name, String id) {
        super(name, id);
    }

    public void setRight(SunNode right) {
        this.right = right;
    }

    public SunNode getRight() {
        return this.right;
    }

    public void setLeft(SunNode left) {
        this.left = left;
    }

    public SunNode getLeft() {
        return this.left;
    }
}
