package com.hpf.mfc.tree;

import com.hpf.mfc.global.InterfaceTree;
import com.hpf.mfc.tree.Node;
import com.hpf.mfc.tree.SunNode;

public abstract class Tree 
    extends SunNode {
    private SunNode root;
    private int memberNum;

    public Tree(String id, String name) {
        super(name, id);
    }

    public void setRoot(SunNode root) {
        this.root = root;
    }
    public SunNode getRoot() {
        return this.root;
    }

    public void setMemberNum(int memberNum) {
        this.memberNum = memberNum;
    }

    public int getMemberNum() {
        return this.memberNum;
    }

    public boolean Add(InterfaceTree member) {
        if (member == null || !(member instanceof SunNode)) {
            return false;
        }
        SunNode temp = (SunNode) member;
        if (hasNode(temp)) {
            return false;
        }
        if (this.nodeHasEmpty(temp)) {
            // id 和 name 都不能为空
            return false;
        }
        if (this.root == null) {
            this.root.setName(temp.getName());
            this.root.setId(temp.getId());
        } else {
            SunNode node = this.root;
            while (node != null) {
                node = (this.toLeft(node, temp)) ? node.getLeft() : node.getRight();
            }
            node = temp;
        }
        this.memberNum++;
        this.Banlance(this.root);
        return true;
    }

    private boolean nodeCantUse(InterfaceTree node) {
        if (node != null && node instanceof SunNode) {
            SunNode temp = (SunNode) node;
            if (this.hasNode(temp)) {
                return false;
            }
        }
        return true;
    }

    public boolean Del(InterfaceTree member) {
        if (this.nodeCantUse(member)) {
            return false;
        }
        SunNode temp = (SunNode) member;
        if (this.idIsEmpty(temp)) {
            // 为保护操作的合法性，要求此处必须为不为空的 id
            return false;
        }
        SunNode node = this.root;
        while (node != null) {
            temp = (this.toLeft(node, temp)) ? temp.getLeft() : temp.getRight();
        }
        if (temp.getLeft().getName() != null) {
            SunNode rightTemp = temp.getRight();
            temp = temp.getLeft();
            if (rightTemp != null) {
                SunNode tempTemp = temp.getRight();
                while (tempTemp != null) {
                    tempTemp = tempTemp.getRight();
                }
                tempTemp = rightTemp;
            }
        } else if (temp.getRight().getName() != null){
            temp = temp.getRight();
        } else {
            temp.setName(null);
            temp.setId(null);
        }
        this.memberNum--;
        this.Banlance(this.root);
        return true;
    }

    public boolean Change(InterfaceTree member, InterfaceTree newMember) {
        if (this.nodeCantUse(member) || newMember == null || !(newMember instanceof SunNode)) {
            return false;
        }
        SunNode temp = (SunNode) member;
        SunNode newTemp = (SunNode) newMember;
        if (idIsEmpty(temp) || nameIsEmpty(newTemp)) {
            // 为保证 change 的合理性与精确性，必须保证 member 的 id 不为空
            // 同时，newMember 的 name 不为空
            return false;
        }
        // 寻找到节点在树中位置
        InterfaceTree nodeAtTree = this.Find(member);
        SunNode node = (SunNode) nodeAtTree;
        if (!idIsEmpty(newTemp)) {
            node.setId(newTemp.getId());
        }
        node.setName(newTemp.getName());
        return true;
    }

    public InterfaceTree Find(InterfaceTree member) {
        if (!(member instanceof SunNode) || member == null || this.memberNum == 0) {
            return null;
        }
        SunNode node = (SunNode) member;
        if (nodeIsEmpty(node)) {
            return null;
        }
        InterfaceTree theNode = idIsEmpty(node) ? findByName(this.root, node) : findById(this.root, node);
        return theNode;
    }

    private SunNode findById(SunNode nowNode, SunNode node) {
        if (node != null) {
            if (node.getId().equals(nowNode.getId())) {
                return nowNode;
            } else {
                this.findById(node.getLeft(), node);
                this.findById(node.getRight(), node);
            }
        }
        return null;
    }

    private SunNode findByName(SunNode nowNode, SunNode node) {
        if (nowNode != null) {
        	if (node.getName().equals(nowNode.getName())) {
        	return nowNode;
        	} else {
        		this.findByName(node.getLeft(), node);
                this.findByName(node.getRight(), node);
                }
        }
        return null;
    }

    public abstract SunNode[] TraversalTree();
        // 遍历树
        // SunNode nodeArray[] = new SunNode()[this.memberNum];
        // this.traversalNode(nodeArray, 0, this.root);
        // return nodeArray;

    private void Banlance(SunNode node) {
        // 平衡树
        if (this.nodeCantUse(node)) {
            return ;
        }
        int leftNum = this.getNodeNum(node.getLeft(), 1);
        int rightNum = this.getNodeNum(node.getRight(), 1);
        int difference = leftNum - rightNum;
        difference = (difference < 0) ? -difference : difference;
        if (difference < 2) {
            return ;
        }
        SunNode temp = node;
        if (leftNum > rightNum) {
            node = node.getLeft();
            temp.setLeft(null);
            SunNode tempTemp = node.getRight();
            while (tempTemp != null) {
                tempTemp = tempTemp.getLeft();
            }
            tempTemp.setRight(temp);
        } else {
            node = node.getRight();
            temp.setRight(null);
            SunNode tempTemp = node.getLeft();
            while (tempTemp != null) {
                tempTemp = tempTemp.getRight();
            }
            tempTemp.setLeft(temp);
        }
        this.Banlance(node.getLeft());
        this.Banlance(node.getRight());
    }

    // 辅助方法
    private boolean hasNode(SunNode node) {
        return (this.Find(node) == null) ? false : true;
    }

    private int getNodeNum(SunNode node, int num) {
        if (!this.nodeCantUse(node)) {
            return 0;
        }
        this.getNodeNum(node.getLeft(), ++num);
        this.getNodeNum(node.getRight(), ++num);
        return num;
    }
    
    public void traversalNode(SunNode nodeArray[], int index, SunNode node) {
        if (this.nodeCantUse(node)) {
            nodeArray[index++] = node;
            this.traversalNode(nodeArray, index, node.getLeft());
            this.traversalNode(nodeArray, index, node.getRight());
        }
    }

    private boolean toLeft(SunNode node, SunNode newNode) {
        int nodeId = Integer.parseInt(node.getId());
        int newNodeId = Integer.parseInt(newNode.getId());
        return (nodeId < newNodeId) ? false : true;
    }

    private boolean toRight(SunNode node, SunNode newNode) {
        int nodeId = Integer.parseInt(node.getId());
        int newNodeId = Integer.parseInt(newNode.getId());
        return (nodeId > newNodeId) ? false : true;
    }

    private boolean nameIsEmpty(SunNode node) {
        return (node.getName().trim().isEmpty()) ? true : false;
    }

    private boolean idIsEmpty(SunNode node) {
        return (node.getId().trim().isEmpty()) ? true : false;
    }

    private boolean nodeHasEmpty(SunNode node) {
        return (this.nameIsEmpty(node) || this.idIsEmpty(node)) ? true : false;
    }

    private boolean nodeIsEmpty(SunNode node) {
        return (this.nameIsEmpty(node) && this.idIsEmpty(node)) ? true : false;
    }
}
