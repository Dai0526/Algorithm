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


### Quora, Reddit
Online Community
这些服务的用户得能发问题或是能分享链接，想象成知乎。。。其他用法则需要能够通过分享的链接，看见这些问题或是留言。
这些服务得能办到：
* 记录每个答案的统计数据，比如阅读数啊，赞，踩等等。
* 用户得能关注其他人或是话题
* 用户需要能获取他们圈子里面的热的话题和问题（和新闻推送服务一样）。



### Dropbox, google drive

需要讨论以下问题：
* 用户如何上传/查看/查询/分享/文件或是图片
* 怎么追踪共享文件的权限
* 怎么实现多用户同时编辑同一文件

### Facebook, Twitter, Instagram
当设计一个拥有上百万级（甚至百亿）用户的社交网络的时候，面试官想知道你是怎么去设计下面这些模块的：
* 高效存储和查询博文或是推文
* 怎么产生新闻推送
* 设计网络图（谁是谁的朋友，谁又粉了谁，特别是百万分数粉名人的时候，想象一下JB或是Lady Gaga，或是你最爱的知乎大V）

很多时候，面试官可能会整场面试就和你讨论怎么设计新闻推送服务。

### Uber, Lyft
Map, Real-time location
当设计这些共享出行服务的时候，咱们需要讨论：
* 最重要的用例：当用户请求用车的时候，怎么才能让用户和附近的黑车快速匹配上。
* 怎么保存上百万用户的地理位置信息，其中既包含司机，也包含乘客，而且他们都是在不断活动的

### Yelp
Location Service
这种服务需要存储巨多人的地理信息。
需要考虑下面的问题：
* 怎么给用户提供搜索周边的人或是事务的功能？
* 怎么给这些地点或是事务排序（比如餐馆。。。）
* 怎么根据人口密度来高效保存地理信息？比如NYC的一个街区可能比一个小城市的景点和游客都要多。


### Web Crawler, auto completion
对于自动搜索补全功能来说，每当用户输入他们的查询，你就应该返回该以该用户输入的句子为开头的前十高票搜索历史。
咱们需要讨论：
* 怎么保存历史信息？
* 怎么保证信息的新鲜度？
* 怎么找到最匹配的历史搜索？
* 怎么处理用户打字太快的情况？


对于网页爬虫功能来说，我们需要设计一个可扩容的服务。从而可以爬取整个网络，同时还是获取茫茫多的网页存档。
需要进行如下讨论：
* 怎么找到新的网页？
* 怎么去优先排序这些一直在变化的动态网页？
* 怎么保证你的爬虫服务不卡在一个主页里面出不来？



### API - Github
当我们需要设计这种有访问速率限制的服务的时候，我们需要考虑这些东西：
* 我们得能限制每个实体一定时间窗口内通过API进行访问的次数
* 该服务在分布式的系统下也应该正常运行，因为这些API能通过不同的服务器进行访问
* 怎么处理节流问题？

## Componments and Utilities
* [Load Balancer](Componments/LoadBalance/LoadBalance.md)


## Learnning Resources 

1. Tools
    * [White Board](https://excalidraw.com/)

2. Resources and Posts
    * donnemartin github [link](https://github.com/donnemartin/system-design-primer/blob/master/README-zh-Hans.md)
    
    * Gainlo Interview Guide [link](https://wizardforcel.gitbooks.io/gainlo-interview-guide/content/sd6.html)
    * Permission/Access Control - from level to policy(authorization) [Link](https://benchling.engineering/evolving-to-enterprise-grade-permissions-493eac166449)
    * http://highscalability.com/
    * https://software.intel.com/content/www/us/en/develop/library.html?query=¤tPage=1&externalFilter=emtcontenttype:webpage/blog;
    * https://instagram-engineering.com/
    * https://engineering.linkedin.com/blog
    * https://docs.microsoft.com/en-us/devops/
    * https://devblogs.microsoft.com/python/
    * https://netflixtechblog.com/
    * https://medium.com/paypal-tech
    * https://engineering.atspotify.com/
    * https://eng.uber.com/
    * https://www.twilio.com/blog
    * https://slack.engineering/
    * https://redditblog.com/
    * https://www.zynga.com/blogs/engineering
3. Courses

4. Engineering Blog
    * [Benchling](https://benchling.engineering/)
    * [Airbnb](https://medium.com/airbnb-engineering)
    * [Atlassian](https://blog.developer.atlassian.com/)
    * [AWS Amazon](https://aws.amazon.com/blogs/aws/)
    * [Dropbox](https://dropbox.tech/)
    * [Quora](https://quoraengineering.quora.com/)
    * [Ebay](https://tech.ebayinc.com/)
    * [Evernote](https://evernote.com/blog/)
    * [Facebook](https://www.facebook.com/Engineering)
    * [Github](https://githubengineering.com/)
    * [AI Google](https://ai.googleblog.com/)
    * [Groupon](https://medium.com/groupon-eng)
    * [Heroku](https://blog.heroku.com/engineering)
5. Video Mock
    * [Interviewing.io](https://interviewing.io/)

	

https://leetcode.com/discuss/general-discussion/1082786/System-Design%3A-Designing-a-distributed-Job-Scheduler-or-Many-interesting-concepts-to-learn