package com.hpf.mfc.link;

import com.hpf.mfc.global.InterfaceLink;

public abstract class Node 
    implements InterfaceLink {
    private String name;
    private int id;
    
    public Node(String name) {
        this.name = name;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public String getName() {
        return this.name;
    }
    
    public void setId(int id) {
        this.id = id;
    }
    
    public int getId() {
        return this.id;
    }
    
    public boolean IsSame(Node node) {
        boolean judge = (this.name.equals(node.getName()) && 
                this.id == node.getId()) ? true : false;
        return judge;
    }
}
