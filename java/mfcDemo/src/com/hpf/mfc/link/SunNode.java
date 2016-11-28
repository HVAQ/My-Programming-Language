package com.hpf.mfc.link;

import com.hpf.mfc.link.Node;

public abstract class SunNode 
    extends Node {
    private SunNode pre;
    private SunNode next;
    
    public SunNode(String name) {
        super(name);
        this.pre = null;
        this.next = null;
    }
    
    public void setPre(SunNode pre) {
        this.pre = pre;
    }
    
    public SunNode getPre() {
        return this.pre;
    }
    
    public void setNext(SunNode next) {
        this.next = next;
    }
    
    public SunNode getNext() {
        return this.next;
    }
}
