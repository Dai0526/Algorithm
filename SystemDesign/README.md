# System Design

## 中心思想
我们不是要选择最佳方案，而是选择`最合适`的方案，只要能说出利弊 (`tradeoff`)，知道如何改进(`scalabe`)，能对于自己的选择给出合理的解释即可。

* Topics
    1. High-level diagram
    2. Data structure and storage
    3. core/sub service design
    4. interface and API design
    5. specialization deep dive
* Requirments
    1. completness
    2. correcntess
    3. tradeoff/scalability

### 扩展性，容错性，延迟要求
* 确认系统在以上三点 Scalability, Fault Tolerance, Latency Requirement是否符合先前定下的需求
* 根据需求进行改进（推荐在第一轮设计中先不考虑这里的三点，先拿下设计和架构能力的分数，再做改进）
* Log，monitor and alert on key metric (系统投入使用前，把系统关键指标 - 之前定义的成功和它的leading indicator，确定下来并且做好监控。）


## Steps to tackle down design problem

System = Services + Data

1. **Scenario**
    * Features
    * Userbase
        * DAU/MAU - to have a estimation of QPS
            * Concurrent Users
                * Peak Users
                * Fast Growing
                
        * `QPS` 
            * QPS = DAU * request per user a day / Total Seconds
            * Read QPS
            * Write QPS

2. **Services**  
    * split large system into small modules and services
    * create interface
3. **Storage**
    * Schema
    * Data
    * SQL/NoSQL
    * Filesystem

4. **Scale**
    * Have solution for future/potential problems
    * Sharding
    * Optimization
        * new features
        * solving design backoff
    * maintenance
        * scalable when QPS increase

### **QPS**

QPS affects the decision in data storage, system scalability, design model, etc.

1. QPS = 100
    * a simple web server


2. QPS = 1000 
	1. a good web server
	2. question about single point failure

3. QPS = 1M
	1. 1000 good web server
	2. how to maintenance if one server is down

QPS -> Webserver and Database  
* 一个webserver大约承受1k QPS (bottleneck of logical processing time and query time)
* SQL DB about 1k QPS
* NoSQL DB(Cassandra) 10k QPS
* NoSQL DB(Memcached) 1M QPS

### Services
逻辑处理的整合，把同类问题归并到相同的service中  
Step 1: **Replay** - give a service tag to each requirement  
Step 2: **Merge** - Merge requirement with the same service


### Storage
Step 1: Select 对每个application/service选择合适的存储结构  
Step 2: Schema 细化数据结构表  

比如结构化信息放到数据库， media信息放到文件系统


* **SQL Database**
    * which info is better to put into relational database
        1. User table
* **NoSQL Database**
	* Which info is better to put into noSql?
        1. tweets
		2. Social graph (followers)
* **File System**
	* Which info is better to put into filesystem
		* Media files - video, image

### Timeline/News Feed Model
* Push
* Pull

### Scale

* Optimize
    * Solving problem
        * Pull vs Push
		* normalize vs De-normalize
	* More Features
        * Edit
		* Delete
		* media
		* Ads
	* Special Cases
        * User with many followers - start
		* Inactive account - zombine account
* Maintenance
	* Robust
	    * what if one DB or server fail
    * Scalability
		* if QPS increase in a short time, how to deal with it


## Examples

### Tiny URL
给定一个（通常为）长的URL，你怎么设计一个服务，能提供短且第一无二的短URL？
这个过程中需要讨论这些问题：
* 怎么给每个URL产生唯一的ID
* 怎么大量生产唯一ID标识（通常每秒都有成千上万这样的请求）
* 你的服务怎么处理重定向	
* 你的服务支持支持定制化短URLs
* 怎么删除过期URLs
* 怎么记录点击数据



### Multi-Media Provider
youtube, netflix, twitch
视频流意味着你的服务需要存储和传输PB （译者：1P = 1024 T, 1T = 1024 G）级别的数据。你应该去讨论如何高效存储和分散数据，从而能让大量的用户无痛且同时观看和分享这些视频（想想一下大家都同时观看冰与火之歌的最后一集）。
* 怎么记录视频的统计数据，比如总观看数，点赞，踩的数量等等
* 怎么实现让用户给视频实时留言


### Chat, Messagener

* 怎么设计用户之间的一对一对话？
* 怎么扩展到群聊？
* 用户没网的时候怎么办？	
* 啥时候应该发推送通知
* 是否能提供端到端加面？以及怎么加密？


