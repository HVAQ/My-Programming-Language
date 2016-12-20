package com.hpf.tools;
/**
 * 双向链表
 * @author whoami
 * 2016.12.04
 * @param <T>
 */
public class TwoWayLink<T> {
	private Node<T> root;
	private Node<T> last;
	private int num;
	public TwoWayLink(T node) {
		new Node<T>(node);
		this.root = null;
		this.last = null;
		this.num = 0;
	}
	public Node<T> getRoot() {
		return root;
	}
	public void setRoot(Node<T> root) {
		this.root = root;
	}
	public Node<T> getLast() {
		return last;
	}
	public void setLast(Node<T> last) {
		this.last = last;
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	private static class Node<T> {
		private int id;
		private T name;
		private Node<T> pre;
		private Node<T> next;
		public Node(T name) {
			this.name = name;
			this.pre = null;
			this.next = null;
		}
		public int getId() {
			return id;
		}
		public void setId(int id) {
			this.id = id;
		}
		public T getName() {
			return name;
		}
		public void setName(T name) {
			this.name = name;
		}
		public Node<T> getPre() {
			return pre;
		}
		public void setPre(Node<T> pre) {
			this.pre = pre;
		}
		public Node<T> getNext() {
			return next;
		}
		public void setNext(Node<T> next) {
			this.next = next;
		}
		public boolean equals(Node<T> node) {
			if (node == null) {
				return false;
			}
			if (this == node) {
				return true;
			}
			if (this.getName().equals(node.getName())) {
				return true;
			}
			return false;
		}
	}
	/**
	 * 实现双向链表的节点增加
	 * @param node 不为空的node
	 * @return 当 node 为空，返回 false
	 */
	public boolean add(T node) {
		if (node == null) {
			return false;
		}
		if (this.hasNode(node) != null) {
			// 链表中不允许出现重复节点
			return false;
		}
		if (this.root == null) {
			this.root = new Node<T>(node);
			this.root.setPre(null);
			this.root.setNext(null);
			this.last = this.root;
		} else {
			this.last.setNext(new Node<T>(node));
			this.last.getNext().setPre(this.last);
			this.last.getNext().setNext(null);
			this.last = this.last.getNext();
		}
		this.last.setId(this.num);
		this.num++;
		return true;
	}
	/**
	 * 节点删除
	 * @param node（id）
	 * @return 节点在链表中存在时，删除，并返回 true
	 */
	public boolean remove(T node) {
		Node<T> temp = this.hasNode(node);
		if (temp == null) {
			// 节点在链表中不存在时，返回 false
			return false;
		}
		if (this.root.equals(temp)) {
			// 需特别处理，否则会造成空指针异常
			this.root = this.root.getNext();
			this.root.setPre(null);
		} else {
			temp.getPre().setNext(temp.getNext());	// 将当前节点的上一节点的下一节点设置为当前节点的下一节点
		}
		this.setAllId();
		this.num--;
		return true;
	}
	public boolean remove(int id) {
		Node<T> temp = this.hasNode(id);
		if (temp == null) {
			return false;
		}
		return this.remove(temp.getName());
	}
	/**
	 * 节点元素修改
	 * @param node（id）
	 * @param newNode
	 * @return 节点在链表中存在，且 newNode 不为空时，修改并返回 true
	 */
	public boolean change(T node, T newNode) {
		if (newNode == null) {
			return false;
		}
		Node<T> temp = this.hasNode(node);
		Node<T> newTemp = this.hasNode(newNode);
		if (temp == null || newTemp != null) {
			// 不能修改为链表中已存在节点
			return false;
		}
		temp.setName(newNode);
		return true;
	}
	public boolean change(int id, T newNode) {
		Node<T> temp = this.hasNode(id);
		if (temp == null) {
			return false;
		}
		return this.change(temp.getName(), newNode);
	}
	/**
	 * 根据 node 查找节点在链表中的索引
	 * @param node
	 * @return 节点在链表中存在时，返回其对应索引，否则返回当前链表存在元素值
	 */
	public int find(T node) {
		Node<T> temp = this.hasNode(node);
		return temp == null ? this.num : temp.getId();
	}
	/**
	 * 根据 id 查找节点在链表中的索引
	 * @param id
	 * @return id 存在于当前链表索引时，返回对应节点，否则返回 null
	 */
	public T find(int id) {
		Node<T> temp = this.hasNode(id);
		return temp == null ? null : temp.getName();
	}
	/**
	 * 遍历链表，node 在链表中是否存在
	 * @param node
	 * @return node 在链表中存在时返回对应节点
	 */
	private Node<T> hasNode(T node) {
		if (node == null || this.root == null) {
			return null;
		}
		Node<T> temp = this.root;
		for (int index = 0; index < this.num && temp != null; index++) {
			if (temp.equals(new Node<T>(node))) {
				break;
			}
			temp = temp.getNext();
		}
		return temp;
	}
	/**
	 * 遍历链表
	 * @param id
	 * @return id 在链表中所对应的节点
	 */
	private Node<T> hasNode(int id) {
		if (id >= this.num || id < 0) {
			return null;
		}
		Node<T> temp = this.root;
		for (int index = 0; index < id; index++) {
			temp = temp.getNext();
		}
		return temp;
	}
	/**
	 * 设置链表索引
	 * 可进行性能优化
	 */
	private void setAllId() {
		Node<T> temp = this.root;
		for (int index = 0; temp != null; index++) {
			if (temp.getId() != index) {
				temp.setId(index);
			}
			temp = temp.getNext();
		}
	}
}
