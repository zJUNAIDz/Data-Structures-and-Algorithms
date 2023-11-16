class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
  insert(data) {
    this.next = new Node(data);
  }
  print() {
    let curr = this;
    while (curr.next != null) {
      console.log(curr.data);
      curr = curr.next;
    }
  }
}

const list = new Node(10);
list.insert(20);
list.insert(30);
list.insert(40);
list.print();
