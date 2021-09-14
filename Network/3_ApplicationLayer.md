# Application Layer



## Transport Layer

### Reliable Data Transfer
Issues:
1. data corrupted
2. segment lost
3. reordered or duplicated

### Data Corruption
* Checksums


### Segment Lost
* Retransmission Timers
* **ACK** to prevent loss

However, **ACK** lost will cause packet duplication. 
- Client send Seg 1
- Client don't receive ACK1
- Client thought Seg 1 not received by Server
- Client send Seg 1 again.

### Segment duplication
1. SEQ - prevent duplication
2. Sliding Window - window move only when all packets received.


### Dection and Retransmission of lost packets
1. Go-Back-N 
    - The simplest sliding window protocol uses go-back-n recovery.
        - It only accepts the segments that arrive in-sequence.
        - It discards any out-of-sequence segment that it receives.
        - When it receives a data segment, it always returns an acknowledgment containing the sequence number of the last in-sequence segment that it has received.
    1. Go-Back-N Receiver
        1. Cumulative Acknowledgements
            - Client sends 1
            - Client sends 2
            - Client sends 3
            - ACK1 and ACK2 lost
            - Client receives ACK 3!
                - It is **OK**! ACK received mean 1 and 2 also received
    2. Go-Back-N Sender
        - A go-back-n sender uses a sending buffer that can store an entire sliding window of segments.
        - The segments are sent with a sending sliding window that we looked at in the last lesson.
        - The sender must wait for an acknowledgment once its sending buffer is full.
        - When a go-back-n sender receives an acknowledgment, it removes all the acknowledged segments from the sending buffer.
            - Client Send 0, 1, 2
            - 1 lost
            - Server will consider both 1 and 2 lost
            - After retransmission timer expires, client resend 1 and 2


Advantage of Go-Back-N
* The go-back-n receiver does not accept out-of-sequence segments.
* The go-back-n sender retransmits all unacknowledged segments once it has detected a loss.

2. Selective Repeat
