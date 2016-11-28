package com.hpf.mfc.link;

import com.hpf.mfc.global.InterfaceLink;
import com.hpf.mfc.link.Node;
import com.hpf.mfc.link.SunNode;

public abstract class Link 
    extends SunNode {
    private SunNode root;
    private SunNode last;
    private int memberNum;
    
    public Link(String name) {
        super(name);
        this.root = null;
        this.last = null;
        this.memberNum = 0;
    }
    
    public void setRoot(SunNode root) {
        this.root = root;
    }
    
    public SunNode getRoot() {
        return this.root;
    }
    
    public void setLast(SunNode last) {
        this.last = last;
    }
    
    public SunNode getLast() {
        return this.last;
    }
    
    public void setMemberNum(int memberNum) {
        this.memberNum = memberNum;
    }
    
    public int getMemberNum() {
        return this.memberNum;
    }
    
    public boolean Add(InterfaceLink member) {
        // 防止链表中出现空节点或重复节点以及不兼容类型
        if (member == null || this.Find(member) <= this.memberNum || 
                !(member instanceof SunNode)) {
            return false;
                }
        SunNode newNode = (SunNode) member;
        if (isEmptyStr(newNode.getName())) {
            return false;
        }
        if (this.root == null) {
            this.root = newNode;
            this.root.setPre(null);
            this.last = this.root;
        } else {
            this.last.setNext(newNode);
            this.last.getNext().setPre(this.last);
            this.last = this.last.getNext();
        }
        this.last.setNext(null);
        this.last.setId(++this.memberNum);
        return true;
    }
    
    public boolean Del(InterfaceLink member) {
        boolean judge = this.Del(this.Find(member)) ? true : false;
        return judge;
    }
    
    public boolean Del(int id) {
        if (id <= 0 || id > this.memberNum) {
            return false;
        }
        if (id == 1) {
            this.root = this.root.getNext();
            this.root.setPre(null);
        } else {
            SunNode temp = findNode(id);
            findNode(id).setNext(temp.getNext().getNext());
        }
        if (id != this.memberNum--) {
            // 如果删除节点为链表的原尾节点，则不用重新设置成员id
            this.setAllId();
        }
        return true;
    }
    
    public boolean Change(InterfaceLink member, InterfaceLink newMember) {
        boolean judge = (this.Change(this.Find(member), newMember)) ? true : false;
        return judge;
    }
    
    public boolean Change(int id, InterfaceLink newMember) {
        if (id <= 0 || id > this.memberNum || newMember instanceof Node) {
            return false;
        }
        Node newNode = (Node) newMember;
        findNode(id).setName(newNode.getName());
        return true;
    }
    
    public int Find(InterfaceLink member) {
        if (member == null || !(member instanceof Node)) {
            return this.memberNum + 1;
        }
        Node node = (Node) member;
        if (this.isEmptyStr(node.getName())) {
            return this.memberNum + 1;
        }
        SunNode temp = this.root;
        int index = 1;
        while (temp != null) {
            if (! temp.getName().equals(node.getName())) { 
                temp = temp.getNext();
                index++;
            } else {
                break;
            }
        }
        return index;
    }
    
    public InterfaceLink Find(int id) {
        InterfaceLink node = (id <= this.memberNum && id != 0) ? findNode(id) : null;
        return node;
    }
    
    private void setAllId() {
        SunNode temp = this.root;
        for (int index = 1; index <= this.memberNum; index++) {
            temp = (temp.getId() == index) ? temp.getNext() : temp;
            temp.setId(index);
        }
    }
    
    private SunNode findNode(int count) {
        SunNode temp = this.root;
        for (int index = 1; index < count; index++) {
            temp = temp.getNext();
        }
        return temp;
    }
    
    private boolean isEmptyStr(String str) {
        boolean judge = str.trim().isEmpty() ? true : false;
        return judge;
    }
}
