# HTTP and HTTPs
HTTP follows a request/response model where a client connected to the server issues a request and the server replies back to it.

An HTTP message (either a request or a response) contains multiple parts:  
* start line  
* headers  
* body  

## **1. HTTP Requests**
```http
GET /players/lebron-james HTTP/1.1
```
Explaination: `GET` the resource at `/players/lebron-james` through version `1.1` of the protocol.

### Header
```http
GET /players/lebron-james HTTP/1.1
Host: nba.com
Accept: */*
Coolness: 9000
```
You can add customer headers such as `Coolness`, etc


## **2. HTTP Responses**
```http
HTTP/1.1 200 OK
Content-Type: application/json
Cache-Control: private, max-age=3600

{"name": "Lebron James", "birthplace": "Akron, Ohio", ...}
```

## **3. Versions**
* HTTP
    * `HTTP/1.0` 
    * `HTTP/1.1`
* HTTPS - secury
* HTTP2 - performance boost by using binary

### **3.1 HTTPS**
**HTTPS** (HTTP Secure) aims to let clients and servers talk securely through **TLS (Transport Layer Security)**, the successor to **SSL (Secure Socket Layer)**.

* **authentication**
* **encryption**

1. To satisfy the client that it is talking to the right server
2. For the parties to have agreed on a “cipher suite”, which includes which encryption algorithm they will use to exchange data
3. For the parties to have agreed on any necessary keys for this algorithm

### **3.2 General Steps to establish SSL connection**
1. Handshake to connection SSL connections
2. Certificate Exchange
3. Key Exchange

### **3.2.1 Authentication**
1. **Public key certificates**
When you connect to an IP address via HTTPS, the server behind that address will present you its certificate for you to verify their identity.

2. **Certificate authority**
When you order a certificate, commonly called an SSL certificate, the authority might give you a phone call or ask you to change a DNS setting in order to verify you’re in control of the domain in question. Once the verification process is complete, it will issue the certificate that you can then install on your webservers

* Trust
* Digital signatures
* Self-signing

### **3.2.2 Encryption**
Encrypt your communication so that only you and your partner will be able to understand your conversation

#### __Encryption via Shared Secret__
Some predefined encryption methods that known to both sides.

#### __Secure exchange of the secret__
Variations of the Diffie-Hellman key exchange protocol are used instead. This ensures parties without prior knowledge can establish a shared secret without anyone else being able to sniff it.



## **4. HTTP Methods**

HTTP Methods:
1. Common:
    1. GET
    2. POST
    3. PUT
    4. DELETE
2. More:  
    1. TRACE
    2. OPTIONS
    3. HEAD 

### 4.1 Get vs POST
```http
GET / HTTP/1.1
```
Difference 1: 
* `GET` requests usually don’t carry a body, so parameters are included in the URL (i.e., www.example.com/articles?article_id=1)  
* `POST` requests are generally used to send (“post”) data which is included in the body

Difference 2: 
Side effects that these verbs carry with them. 
* `GET` is an idempotent verb, meaning no matter how many requests you will send, you will not change the state of the webserver. 
* `POST` is not idempotent; for every request you send you might be changing the state of the server.

### Sending data in the body is safer than in URL
**1. Avoid logging sensitive data since URL are usually saved in log**  
From here we can derive that `POST` and other, non-idempotent methods are safer than `GET`, even though it’s more a matter of how data is sent when using a particular verb rather than a specific verb being intrinsically safer than others. If you were to include sensitive information in the body of a `GET` request, you’d face no more problems than when using a `POST`, even though the approach would be considered unusual.