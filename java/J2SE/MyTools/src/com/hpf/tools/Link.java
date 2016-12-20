package com.hpf.tools;

/**
 * 单向链表
 * @author whoami
 * 2016.12.03
 * @param <T>
 */
public class Link<T> {
	private Node<T> root;
	private int num;
	public Link(T name) {
		new Node<T>(name);
		this.root = null;
		this.num = 0;
	}
	public Node<T> getRoot() {
		return this.root;
	}
	public void setRoot(Node<T> root) {
		this.root = root;
	}
	public int getNum() {
		return this.num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	private static class Node<T> {
		/**
		 * 内部节点类
		 * 可通过泛型 T 来拓展节点
		 */
		private T name;
		private int id;
		private Node<T> next;
		public Node(T name) {
			this.name = name;
			this.next = null;
		}
		public T getName() {
			return this.name;
		}

		public void setName(T name) {
			this.name = name;
		}

		public int getId() {
			return this.id;
		}
		public void setId(int id) {
			this.id = id;
		}
		public Node<T> getNext() {
			return this.next;
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
			if (this.name.equals(node.getName())) {
				return true;
			}
			return false;
		}
		public void showAll() {
			System.out.println(this.id + 1 + "\t" + this.name);
		}
	}
	/**
	 * 节点的增加
	 * @param node
	 * @return 当节点为空或节点与链表中已有元素相同时，返回 false
	 */
	public boolean add(T node) {
		if (node == null) {
			return false;
		}
		if (this.root == null) {
			this.root = new Node<T>(node);
			this.root.setId(this.num);
		} else {
			Node<T> temp = this.root;
			if (temp.equals(new Node<T>(node))) {
				// 不能增加与链表中已有元素相同的元素
				return false;
			}
			while (temp.getNext() != null) {
				if (temp.getNext().equals(new Node<T>(node))) {
					// 不能增加与链表中已有元素相同的元素
					return false;
				}
				temp = temp.getNext();
			}
			temp.setNext(new Node<T>(node));
			temp.getNext().setId(this.num);
		}
		this.num++;
		return true;
	}
	/**
	 * 节点的删除
	 * @param node
	 * @return 当节点在链表中不存在时，返回 false
	 */
	public boolean remove(T node) {
		Node<T> temp = this.getNode(node);
		if (temp == null) {
			return false;
		}
		// 不能只使用this.getNode(node).getid()，可能会出现空指针异常
		return this.remove(temp.getId());
	}
	/**
	 * 通过节点 id 实现对节点的删除
	 * @param id
	 * @return 当传入 id 大于链表的最大索引或小余0时，返回 false
	 */
	public boolean remove(int id) {
		if (id >= this.num || id < 0) {
			return false;
		}
		if (id == 0) {
			this.root = this.root.getNext();
		} else {
			Node<T> temp = this.root;	// 记录要删除节点的上一个节点
			for (int index = 1; index < id && temp.getNext() != null; index++) {
				temp = temp.getNext();
			}
			// 特殊处理链表的尾节点，否则会出现空指针异常
			if (id == this.num - 1) {
				temp.setNext(null);
			} else {
				temp.setNext(temp.getNext().getNext());
			}
		}
		this.setAllId();
		this.num--;
		return true;
	}
	/**
	 * 将链表中的 node 修改为 newNode
	 * @param node
	 * @param newNode
	 * @return 如果 node 在链表中不存在或 new 在链表中存在，返回 false
	 */
	public boolean change(T node, T newNode) {
		Node<T> temp = this.getNode(node);
		Node<T> newTemp = this.getNode(newNode);
		if (temp == null || newTemp != null) {
			// node 必须在链表中存在，newNode 在链表中不能存在
			return false;
		}
		temp.setName(newNode);
		return true;
	}
	/**
	 * 通过节点 id 实现对节点的修改
	 * @param id
	 * @param nowNode
	 * @return 当节点 id 大于链表最大索引、小余0、newNode 为空
	 * 或 newNode 在链表中已经存在时，返回 false
	 */
	public boolean change(int id, T newNode) {
		Node<T> temp = this.getNode(id);
		if (temp == null) {
			return false;
		}
		// 不能直接使用 this.getNode(id).getName()，可能会出现空指针异常
		return this.change(temp.getName(), newNode);
	}
	/**
	 * 通过 id 查找节点
	 * @param id
	 * @return 当 id 不大于链表最大索引，不小于0，返回对应节点，否则返回 null
	 */
	public T find(int id) {
		Node<T> temp = this.getNode(id);
		return temp == null ? null : temp.getName();
	}
	/**
	 * 通过节点查找索引
	 * @param node
	 * @return 当节点在链表中存在时，返回其索引，否则返回链表成员索引数
	 */
	public int find(T node) {
		Node<T> temp = this.getNode(node);
		return  (temp == null) ? this.num : temp.getId();
	}
	public void showAll() {
		Node<T> temp = this.root;
		while (temp != null) {
			temp.showAll();
			temp = temp.getNext();
		}
	}
	/**
	 * 通过 node 找到其在节点中的位置
	 * @param node
	 * @return 在链表中的对应节点
	 */
	private Node<T> getNode(T node) {
		if (node == null || this.root == null) {
			//  传入节点不能为空，链表不能为空
			return null;
		}
		Node<T> temp = this.root;
		while (temp != null) {
			if (temp.equals(new Node<T>(node))) {
				break;
			}
			temp = temp.getNext();
		}
		return temp;
	}
	/**
	 * 通过 id 找到其在节点中的位置
	 * @param id
	 * @return 在链表中的对应节点
	 */
	private Node<T> getNode(int id) {
		if (id >= this.num || id < 0) {
			// 传入 id 不能大于链表最大索引或小余0
			return null;
		}
		Node<T> temp = this.root;
		while(temp != null) {
			if (temp.getId() == id) {
				break;
			}
			temp = temp.getNext();
		}
		return temp;
	}
	/**
	 * 设置链表节点的索引
	 * 服务与 remove() 方法
	 * 可进行性能调优
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