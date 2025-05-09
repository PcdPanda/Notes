- [Handbook of Fixed Income](#handbook-of-fixed-income)
    - [1. 固定收益市场概述](#1-固定收益市场概述)
        - [1.1 证券属性](#11-证券属性)
        - [1.2 资产风险](#12-资产风险)
        - [1.3 一级市场和二级市场](#13-一级市场和二级市场)
        - [1.4 市场指数](#14-市场指数)
    - [2. 固定收益证券价值分析](#2-固定收益证券价值分析)
        - [2.1 债券定价](#21-债券定价)
        - [2.2 债券收益率计算](#22-债券收益率计算)
        - [2.3 利率风险,久期和凸性](#23-利率风险久期和凸性)
        - [2.4 利率结构分析](#24-利率结构分析)
        - [2.5 拟合利率曲线](#25-拟合利率曲线)
        - [2.6 带期权的债券定价](#26-带期权的债券定价)
        - [2.7 基本的债券调仓策略](#27-基本的债券调仓策略)
        - [2.8 实现收益率计算](#28-实现收益率计算)
    - [3. 政府发行证券](#3-政府发行证券)
        - [3.1 美国国债](#31-美国国债)
        - [3.2 地方债](#32-地方债)
        - [3.3 (逆)回购](#33-逆回购)
        - [3.4 Dollar Row](#34-dollar-row)
        - [3.5 联邦基金利率](#35-联邦基金利率)
        - [3.6 通胀债券 (TIPS)](#36-通胀债券-tips)
    - [4. 私人信贷证券](#4-私人信贷证券)
        - [4.1 商业汇票 (Commerical Paper)](#41-商业汇票-commerical-paper)
        - [4.2 银行承兑汇票 (Banker Acceptances)](#42-银行承兑汇票-banker-acceptances)
        - [4.3 存托凭证 (Certificate of Deposit)](#43-存托凭证-certificate-of-deposit)
    - [5. 企业固定收益证券](#5-企业固定收益证券)
        - [5.1 利息](#51-利息)
        - [5.2 信用担保](#52-信用担保)
        - [5.3 债券风险](#53-债券风险)
        - [5.4 高风险/收益债券](#54-高风险收益债券)
        - [5.5 回购计划](#55-回购计划)
        - [5.6 中期票据 (Midterm-Notes)](#56-中期票据-midterm-notes)
        - [5.7 优先股](#57-优先股)
    - [6. 另类债券](#6-另类债券)
        - [6.1 浮动利率债券 (Floating Rates Bond)](#61-浮动利率债券-floating-rates-bond)
        - [6.2 Foreign Bonds](#62-foreign-bonds)
        - [6.3 Emerging Market Bonds](#63-emerging-market-bonds)
        - [6.4 Stable Value Investments (Guaranteed Investment Contract)](#64-stable-value-investments-guaranteed-investment-contract)
    - [7. 可转债](#7-可转债)
        - [7.1 可转债定义](#71-可转债定义)
        - [7.2 转换分析](#72-转换分析)
        - [7.3 价值分析](#73-价值分析)
        - [7.4 估值模型](#74-估值模型)
        - [7.5 可转债变种](#75-可转债变种)
    - [8. 信用衍生品](#8-信用衍生品)
        - [8.1 债券期货/远期合约](#81-债券期货远期合约)
        - [8.2 利率掉期互换](#82-利率掉期互换)
        - [8.2 利率期权](#82-利率期权)
        - [8.5 信用违约互换(CDS)](#85-信用违约互换cds)
    - [9. Mortage-Backed Securities](#9-mortage-backed-securities)
        - [9.1 Mortage Overview](#91-mortage-overview)
        - [9.2 Agency MBS](#92-agency-mbs)
        - [9.3 Collateralized Mortage Market](#93-collateralized-mortage-market)
        - [9.4 Subprime ABS](#94-subprime-abs)
        - [9.5 Commerical Mortage Backed Securities (CMBS)](#95-commerical-mortage-backed-securities-cmbs)
    - [10. Other Asset Backed Securities](#10-other-asset-backed-securities)
        - [10.1 Credit Card ABS](#101-credit-card-abs)
        - [10.2 Automobile Lease Backed Securities](#102-automobile-lease-backed-securities)
        - [10.3 CDO](#103-cdo)
        - [10.4 Synthetic CDO](#104-synthetic-cdo)
    - [11. Credit Analysis:](#11-credit-analysis)
        - [11.1 Financial Analaysis:](#111-financial-analaysis)
        - [11.2 Incomplete-Information Credit Models $(I^2)$](#112-incomplete-information-credit-models-i2)
        - [11.3 Municipal Obligation and Revenue Bond](#113-municipal-obligation-and-revenue-bond)
        - [11.4 Rating Agency Approach](#114-rating-agency-approach)
    - [11. Bond Portfolio Management](#11-bond-portfolio-management)
        - [11.1 Benchmark Selection](#111-benchmark-selection)
        - [11.2 Benchmark Tracing](#112-benchmark-tracing)
        - [11.3 Enhancement Strategy](#113-enhancement-strategy)
        - [11.4 Cash-flow Matched Portfolio](#114-cash-flow-matched-portfolio)
        - [11.5 International Management](#115-international-management)
        - [11.6 Transitional Management](#116-transitional-management)

# Handbook of Fixed Income
### 1. 固定收益市场概述
##### 1.1 证券属性
- 证券发行: 企业/地方政府/中央政府。
- 风险背书: 抵押物/政府信用/项目收入。
- 债券回购: 企业和地方政府会在利率较低的时候回购旧债发新债。具有回购期权属性的债券对投资者不利,因为价格有上限且利息不稳定。
- 期权属性: 投资者可能有卖出期权,甚至转股和转到其他公司债券的权利,用转换比定价。
- 利息: 固定/基于项目收入/基于市场指标/区间内浮动/设定变动阈值。
- 优先股: 优先股属于分红,但是投资人有税务优惠,因此降低企业的发行成本,<u>优先股几乎都有沉没条款</u>。
- ABS/MBS: 基于房贷收入的债券,通过房贷池分散风险,并且可以进一步划分为基于本金和利息的债券,在低利率环境下回购风险大。
##### 1.2 资产风险
- 市场风险: 固定收益最大的风险,通常源于<u>利率上升</u>导致的价格下降,可以用久期衡量市场风险。
- <u>再投资风险</u>: 发债方会在<u>低利率</u>的时候回购债券,此时很难找到再投资的替代品。
- 赎回风险: 赎回时间的不确定性使得很难给债券定价,并且限制了价格的上涨空间。
- 信用风险: 企业经营不善导致的违约风险和评级公司调节评级带来的价格波动风险。
- 流动性风险: 流动性差的债券很难快速变现。
- <u>波动率风险</u>: 有期权属性的债券对于市场波动率会很敏感。
- 其他风险: 汇率/政治/法律/购买力/黑天鹅/产业风险。
##### 1.3 <u>一级市场和二级市场</u>
- 一级市场发行: 投行协助发行方给债券定价并承销给市场,为了降低风险,投行会成团一起承销,通常有买断发行和竞标发行两种方法。
- SEC发行法规: 发行前先要在SEC注册,但是两年内不用反复注册。<u>144A免除了私人发行发行2年内不能转售和必须注册的条款,吸引了大量国际投资者</u>。
- 私人市场发行: 不能对大众宣传,可以免除一定注册条款。投资者可以和发行方商讨债券的属性细节,但是因为流动性差,风险也高。
- <u>二级市场</u>: 交易员基于面值比率报价,通常假设面值是100。现在大部分交易依然通过和dealer的点对点报价在OTC执行。美国债券是T+2交易,包括达成价格共识,资金和证券清算转账,并通过TRACE报备。
##### 1.4 市场指数
- 市场规模: 债券市场总市值和权益市场大致相等,但是历史只有50年左右,也没有成熟的电子交易系统,只有30%的交易完全电子化。
- 市场多样性: 由于债券的属性繁多,市场里有大量不同的投资标的,因此很难做出全面具有代表性的指数来评估中性表现。
- IG指数: 由BBB及以上债券构成的指数,通常是市值加权,并由交易员报价来计算每个成分的价格。指数内不同评级的债券收益率相关性很大,因为利率几乎是唯一变量。
- HY指数: 由BBB之下债券构成的指数,因为HY债券经常违约,且流动性差,更难计算价格。<u>HY种类内部债券相关性同样很大,但是和IG指数相关性很低</u>。
### 2. 固定收益证券价值分析
##### 2.1 <u>债券定价</u>
- 常规债券定价: 选择合适的折现率(通常用对应时间的无风险利率),把每一笔现金流当做0息债券进行折现。<u>当无期权债券折现率等于利率时,价格等于债券面值</u>。
- <u>期中债券定价</u>: 因为债券利息是定期支付的,在期中交易的话要公平的分配应计利息。
  1. 计算距离下一次付息日的天数差$n$,国债用实际天数,企业债和地方债则统一把每个月当做30天处理。
  2. 计算折现日期比$w=\frac{n}{P}$, $P$是付息周期长度。
  3. <u>用折现法并带入$w$计算dirty price (full price), 这样计算因为最近这笔利息发给卖家</u>。
   $$P=\sum_{i=0}^{n-1}\frac{c}{(1+r)^{i+w}}+\frac{\text{Par}}{(1+r)^{n-1+w}}$$
  4. 计算应计利息$AI=C\frac{P-n}{P}$, clean price就是dirty price减去应急利息$P_c=P-AI$
- 报价习惯: 美国通常用clean price报价,但是支付dirty price,因为dirty price假设利息全在付息日支付买方而卖方没有利息。
##### 2.2 债券收益率计算
- 当前收益率 Current Yield: 利息除以当前债券价格,简单方便,但是没有考虑到本金和再投资因素。
$$Y_{\text{current}}=\frac{C}{P}$$
- 到期收益率YTM: 找到使得债券现值等于当前市场报价的折现率。<u>这个收益率假设了再投资收益率等于YTM,没有考虑再投资风险,因此会高估价格</u>。
$$r\rightarrow P(r)=P$$
- 赎回收益率YTC: 假设债券在第一个可赎回日到期赎回,计算使得折现价格等于现价的折现率,同样没有考虑再投资风险。
- 浮动利率债券收益率: 假设未来浮动利率不变计算现金流和YTM,获得YTM减去标定利率的spread。缺陷在于没有考虑浮动利率的变化和利息上下限。
- <u>全收益分析</u>: 定义投资时长,再投资利率(可以通过远期利率获得)和投资到期日出售价格来重新计算现金流,同时可以考虑税务问题。<u>适合做网格分析来获得各种情况的收益率分析并对比不同债券的表现</u>。
- <u>投资组合全收益计算</u>: 不能直接对所有成分债券的收益率进行加权,而是<u>重新计算所有的现金流折现加权计算</u>。
##### 2.3 <u>利率风险,久期和凸性</u>
- 利率风险: 令函数$P(r)$描述债券在利率是$r$时的价格,获得在不同$r$情况下的$P(r)$价格变化比例,用于评估对于利率变动的风险。
- <u>久期</u>: $P(r)$对于$r$的斜率,<u>利息越高/到期时间越长/$r$越小,久期越大</u>。通常选取一个20bp左右的$\Delta r$来计算久期
$$D=\frac{P(r-\Delta r) - P(r-\Delta r)}{2P(r)\Delta r}$$
- <u>凸性: </u>因为久期线性逼近误差较大,考虑凸性作为二阶拟合。在不受赎回债券影响的情况下,通常凸性为正数,<u>同时凸性越大的债券,在利率变动相同时,涨的比跌的更多</u>。
$$C=\frac{P(r-\Delta r) + P(r-\Delta r)-2P(r)}{P(r)\Delta r^2}$$
- <u>债券价格变化率的近似逼近</u>: 把久期当做斜率,凸性当做二阶导,来考虑$P(r)$的变化,注意要考虑单位影响。
$$P(r)=-D\Delta r+\frac{1}{2}C\Delta r^2$$
- PVBP/DV01: 在利率变化为1bp的情况下$P(r)$的变化量,因为范围小,通常用久期表示就够了,不需要考虑凸性。
- </u>召回期权影响</u>: 债券还要减去买入集权的价值,因此<u>在利率下降时,凸性变为负数,价格不会继续上升</u>,整个价格曲线为反向的S型
- 卖出期权影响: 债券还包含了卖出期权的价值,因此在利率上升时,凸性变大,价格不会进一步下跌
- 麦考利久期/修正久期/修正凸性: 假设现金流不会因利率改变,只修改折现率重新计算的久期和凸性,可以用于简化计算,但在含有期权属性时不准。
$$\text{Macaulay Duration}=\frac{\sum_{i=1}^n\frac{CF_i}{r^i}}{n\cdot P}$$
$$\text{Modified Duration}=\text{Macaulay Duration}\frac{1}{1+\text{YTM}/n}$$
- <u>投资组合久期</u>: 投资组合的久期是各个债券久期的市值加权,并且还要考虑到利差久期的计算。
- 浮动利率债券: 距离债券重置日期的天数越多,久期越大,同时还要考虑投资者对利差的需求和利息上限的影响。
##### 2.4 <u>利率结构分析</u>
- <u>基准利率(现货利率): 国债收益率无法直接作为基准利率,因为利息通过短期利率折现了</u>,因此需要先从最短期国债出发获得短期收益率,折现长期国债利息后,再计算对应的长期现货利率。
- 风险溢价: 基准利率之上的额外利率,取决于发行方信用,债券流动性,税务关系,评级,债券到期时间和附带的期权属性。
- <u>远期利率</u>: 在没有套利和交易摩擦的情况下,$t_0\sim t_2$的利率$r_{0\sim2}$应该等于子区间利率的乘积$r_{0\sim1}\cdot r_{1\sim2}$,因为通常已知从$t_0$开始的利率,所以可以估计远期利率$r_{1\sim 2}=\frac{r_{0\sim2}}{r_{0\sim1}}$
- <u>利率之间的关系</u>: 现货利率是远期利率的几何平均数,基准利率是现货利率现金流加权后的结果,因此波动以此减小
- 决定长期利率的因素: 由于这些因素不会完全包含在远期利率中,因此可能造成远期利率估计误差
  - 市场期望: 基于正确的远期利率期望出发,构造的长期利率
  - 时间风险溢价: 基于债券的beta/到期时间带来的风险,会受到投资者风险偏好的影响。<u>经济过热,利率曲线陡峭时会上升,在经济下挫,债券作为避险属性的情况下会下降,甚至为负数</u>。
  - 凸性偏好: 长期无权债券凸性很大,带来投资优势,在波动率高的市场会进一步放大,因此导致收益率降低。
##### 2.5 <u>拟合利率曲线</u>
1. 使用零息债券获得现货利率,再结合现货利率获得远期利率,这种方法可以获得单点的利率
2. 搭建利率模型
   - Spline Cubic Models: 以时间为自变量,单点为分割的分段3次函数,使用OLS拟合函数系数,注意在单点必须可导。
   - Svensson model: 拟合指数函数($\beta, c$)
    $$r_f(t)=\beta_0+\beta_1\exp\frac{-t}{c_1}+\beta_2\frac{t}{c_1}\exp\frac{-t}{c_1}+\beta_3\frac{t}{c_2}\exp\frac{-t}{c_2}$$
3. 分析拟合效果时要同时考虑精确度,可解释性和稳定性。
4. 对冲利率风险: 计算整个投资组合对$\beta$的导数,使其尽可能等于0。如果只考虑利率的微小变化,那么只要使得久期和凸性为0即可。
##### 2.6 <u>带期权的债券定价</u>
1. 生成并校准利率变动路径: 选择合适的利率波动率,生成利率路径网,使得不同期限的零息债券在不同路径折现后的平均价格等于当前市场价
2. 基于路径对债券定价: 基于上面生成的利率路径,对债券未来的现金流进行折现,如果债券包含期权,则会在对应时刻行权。
3. 计算OAS:在利率路径上加上OAS息差对债券进行折现,OAS使得折现后的价格等于当前市场价。
4. 计算OAD: 分别对考虑OAS之后的利率曲线进行上移和下移,随后重新计算债券价格,$OAD=\frac{P_-P_+}{2P_0\bigtriangleup r}$,OAC同理$\frac{P_-+P_+-2P_0}{2P_0(\bigtriangleup r)^2}$。
5. 如果是类似MBS的复杂衍生品,还要考虑再融资利率等因素随利率的变动情况。
6. <u>有效期限</u>:定义为利息率和久期相近的零息债券的期限。通常将有效期限和利息率相似的债券对比分析。 
##### 2.7 基本的债券调仓策略
- 流动性控制: 使用全收益分析找到和当前债券在评级,收益率等性质上相似的流动性强的债券来替换组合中的流动性差的债券。
- 对未来利率预期/利差和市场不同,因此可以计算基于自己预期下的债券价格,并进行低买高卖。
- 找到<u>远期利率中被错误定价</u>的部分,例如认为$t_1\sim t_2$期间利率定价过高,则可以通过做多$t_0\sim t_2$,做空$t_0\sim t_1$让自己仅暴露在$t_1\sim t_2$的利率变化中
- 在利率曲线陡峭的时候进行<u>久期中性套利</u>: 在长期债券利率和中期利率近似的情况下,做空短期和长期利率,做多中期债券,在久期不变的情况下,提高综合收益率。
##### 2.8 实现收益率计算
- 流动性问题: 当因为流动性不好而无法对成分债券进行合理定价时,最好选择相似且流动性好的债券的价格替换。
- 投资收益率: 可以考虑在投资阶段客户投入资金/取出资金对收益率的影响,但是没有具体考虑客户入金/出金的时点
$$\text{ROI}=\frac{(\text{EndMarketValue}+\text{NetOutCash})-(\text{BeginMarketValue}+\text{NetInCash})}{\text{BeginMarketValue}+\text{NetInCash}}$$
- <u>金钱加权收益率 (MWR)</u>: 综合评估投资组合表现,反应了客户的体验
  1. 对于每一笔现金流$M_i$,计算它在整个计算周期中被用于投资的日期的比例$n_i$,如果是一开始就在组合中的话则$n_i=1$
  2. 带入每一笔现金流价格和时间比率,找到使得终值为EndMarketValue的MWR,这里假设了MWR在整个投资周期中不变。
    $$\sum M_i(1+\text{MWR})^{n_i}=\text{EndMarketValue}$$
  3. 用 Modiﬁed Dietz Return作为MWR的近似简便计算
    $$R=\frac{\text{EndMarketValue}-\text{BeginMarketValue}-\text{TotalNetCashFlow}}{\text{BeginMarketValue}+\sum n_i\cdot\text{NetCashFlow}_i}$$
- <u>时间加权收益率 (TWR)</u>: 在每一次客户入金和出金的时候计算子区间收益率,并累成获得综合收益率。适合单独评估经理的投资表现,排除了客户的影响。在计算成本高的时候可以牺牲精度扩大子区间范围,并用子区间$MWR$近似。

### 3. 政府发行证券
##### 3.1 美国国债
- T-bills: 1年内的到期,无利息,每周通过折价发行,报价习惯为年化折现率$Y=\frac{\text{Par}-\text{Price}}{\text{Par}}\cdot\frac{365}{t}$。
- T-Notes: 2-10年到期,2/5年期限的国债每月发行,3/10年的国债每季发行。
- T-bonds: 期限大于10年。
- 竞标方式
  1. 投资者选择参与竞价竞标/非竞价竞标。
  2. 竞价竞标遵循价格优先,直到竞标发行额度被全部匹配,此时的竞标收益率为发行收益率,并适用于非竞价竞标
- 国债回购: 财政部/美联储会在二级市场直接回购国债,而不是通过期权中回购选项。
- 二级市场: 24小时交易,<u>最新发行的国债交易最活跃,可以占到总交易量的70%</u>。
- 国债拆组: 可以把国债的本金和利息拆分为不同债券交易,本金成为零息折现债券,也可以重组。
- 政府机构债券: 由政府支持的私人机构发行,例如Fannie Mae,因此几乎没有信用风险,获得的现金通常用于给市场提供流动性。
##### 3.2 地方债
- 信用背书: 地方债的背书来源于税收和公共设施收入,信用仅次于国债,但是<u>曾经也有违约经历</u>。
- 二级市场: 地方在通常在OTC交易,使用YTM报价,通常收益率随着期限增加而上升。主要投资者是<u>当地散户</u>,但是共同基金投资者的占比也在迅速上升。
- 利息计划: 根据债券种类,利息可以固定/周期性重置/和标定利率走势相反,收入在<u>发行地区免税</u>,并且免于SEC注册。
- 衍生品: 和国债类似,地方债也可以将本金和利息拆分并重新组合成不同产品,但是都采用传统的现金流折现定价。
##### 3.3 <u>(逆)回购</u>
- 回购: 将证券抵押换取现金流,并在指定日期附带利息购回抵押证券。抵押期间抵押物的现金流依然由原持有人所有,最后需要偿还。
- 保证金: 回购者需要缴纳保证金,以防因为利率上升抵押品贬值而拒绝回购。
- 逆回购: 和回购相反,支付现金流购买证券,并在日后获得本金和利息。
- 交割成本: <u>回购的时间间隔非常短</u>,因此相对的清算交割成本非常高,通常由第三方机构负责清算来降低成本。
- 回购利率: 由无风险利率/抵押品质量/回购条款期限/清算成本共同决定,通常比银行利率低一些。美联储通过逆回购市场的公开市场行为调控利率。
##### 3.4 Dollar Row
- 和逆回购类似,但是逆回购不用交还完全一样的抵押物,由于逆回购方自由度更高,因此回购利率也更低。
- 抵押物带来的现金由接受抵押方所有,不需要偿还,因此对于预付款需要特别处理,否则对回购方不利。
##### 3.5 <u>联邦基金利率</u>
- <u>联邦基金</u>: 银行存在美联储的准备金,没有利息收入。
- 联邦基金利率: 银行之间互相借贷准备金的利率,通常受到美联储的公开市场行为控制。
- <u>利率作用</u>: 是全市场的标定利率,因为联邦基金借贷没有抵押物,因此利率通常比REPO高25bp。
##### 3.6 通胀债券 (TIPS)
- <u>发行方式</u>: 事先确定需要达成的真实利率,基于CPI指数调整本金来提高返回的利息,但是<u>有3个月的延迟</u>,国际上有<u>ILB指数</u>描述全球的TIPS债券情况。
$$1+名义利率=(1+真实利率)\cdot(1+通胀率)$$
- <u>真实久期(Real Duration)</u>: 由于TIPS和其他资产的相关性极低,需要Real Duration来表示债券价格对真实利率变化的敏感度。
- 有效久期(Effective Duration): TIPS对名义利率变动的敏感度,在和其他资产一起分析时使用,通常直接等于$0.75\cdot\text{Real Duration}$
- breakeven rate: 让TIPS名义利率等于常规国债利率所需的通胀率,通常为0.5%,因为国债已经考虑到了一些通胀因素。
- 使用方式: 在真实利率大于2%以上时基本可以超过其他无风险债券,并且可以作为单独的资产类别用来对冲通胀风险。<u>政府可以通过增发TIPS来表示控制通胀的决心,并且保证即使在通缩情况下,债券也不会贬值</u>。
### 4. 私人信贷证券
##### 4.1 商业汇票 (Commerical Paper)
- 期限范围: 银行持有的短期债券,为了可以向美联储贴现窗口质押换区现金流,<u>通常期限在45日内以内</u>,为了免于SEC注册,最高期限不会达到270天。
- 市场规模: 总市值大于短期美国国债,但是交易活跃度不如国债,因此会有15bp左右的利差
- 发行者: 主要由金融公司发行,通常为制造业母公司融资。
##### 4.2 银行承兑汇票 (Banker Acceptances)
- 发行方式: 由银行替第三方机构代表的债务,用于提高第三方机构之间的交易效率。
- 发行者:资质良好的银行不需要准备金也可以发行承兑汇票,因此信用风险来源于银行和第三方机构同时违约。
##### 4.3 存托凭证 (Certificate of Deposit)
- 发行者: 银行发行的客户存款证明,通常FDIC可以提供一定数额的保险。
- 二级市场: 起初客户如果提前想提前取出定期存款,则必须缴纳罚金,存托凭证市场使得他们可以通过转卖凭证获取现金,并且扩大了市场。
- 收益率: 会受到银行信誉/期限/供求关系/银行发行计划等多种因素影响
- 境外产品 (Euro CD): 用美元计算收益,但是因为海外准备金和监管要求比美国本土低,并且存在境外主权风险,可以提供比本土更高的收益率。
### 5. <u>企业固定收益证券</u>
##### 5.1 利息
- 面值: 通常以1000为面值发行,并通常在市场上用clean price报价,dirty price交易
- Stright Coupon: 利率固定,如果是国际公司可能会有利率风险。
- Income Coupon: 基于项目收益的债券,如果无法偿还利息不算做违约。
- Pay-In-Kind: 允许利息较晚发放,或者利率逐步升高,甚至以新债券作为利息发放,通常由陷入财务困难的公司发行。
- Zero-Coupon: 折价交易的无息债券,没有再投资风险,通常具有回购期权属性。<u>由于只有一笔现金流,期限很长的无息债券风险较高</u>
##### 5.2 信用担保
- 担保人: 债务公司会寻找受托人担任债权人的担保人,用于为债权人维护条款内的利益。
- 担保物: 公司的基本面比担保物更加能决定债务质量,担保物包括实体资产/股权质押/设备信用凭证(ETC)
- 系列债券: 随着债务逐步还清,债务公司重复使用担保物继续发行新债券,但是新债券面值受到担保物价值和公司盈利的限制。
- <u>无担保债券 (Debenture)</u>: 没有资产抵押的债券,适用于长期但是数额较小的融资需求。公司需要尽力维持足够的流动资产来偿还债券,并且投资者在违约时任有权从资产负债表上获得赔偿。
- 公司担保债券: 通常由另一家公司担保的债券,只有在两家公司同时违约的时候才会出现信用危机。
- 维护置换基金(M&R Funds): 债权人设立基金来维护抵押品,确保其没有贬值,并且不能自行把抵押品换成现金。
##### 5.3 <u>债券风险</u>
- Credit Risk: 取决于公司基本面等多方面因素,但是大家一般参考评级机构标准,BBB-级以上是投资级别(IG)债券,BB+级以下是高收益(HY)债券。
- Rating Transition Table: 评级机构会定期发布不同级别公司债务转换的数量统计,使投资者直观了解债务可靠性。
- <u>Credit Spread Risk</u>: 由于债券的信用利差变化带来的价格风险,通常可以用<u>spread duration</u>衡量。
- <u>Event Risk</u>: 债务公司管理层行为带来的风险,例如发放分红/资产重组后导致杠杆率提高带来的风险。债务人可以在债券条款中加入卖出期权来限制这些行为并减少风险。
##### 5.4 高风险/收益债券
- 高收益债券的产生原因: 年轻公司缺乏信誉基础/好公司经营不善信用不断恶化/杠杆率过高信用下降。
- <u>债券特征</u>: 价格波动较大,但是平均回报较低,利息通常采用Pay-In-Kind模式。
- <u>违约率</u>: 可以基于违约公司计算,也可以基于违约债券的总面值计算,在后者情况下分母还可以根据债券期限加权 
- <u>回收率</u>:回收率保证了即使公司违约依然可以获得一定赔偿,债券资级越高,获得赔付的优先级也越高。
##### 5.5 <u>回购计划</u> 
- 赎回条款: 公司可处于低利率/财务状况/资本结构等因素回购债券,回购价可以是固定的面值或者基于当前利率下的NPV。
- 沉没基金条款: 公司必须在发行债券的时候根据条款上规定的计划逐步回购债券,可以有效降低投资者面临的信用风险,但是回购价格可能对投资者不利。
- 要约收购 (Tender Offer): 公司临时向投资者提出的债券回购,可以在和投资者达成协议后实行。
##### 5.6 中期票据 (Midterm-Notes)
- 发行方: 信誉良好并且需要持续稳定发行债务的公司,总量通常在1亿到10亿之间。
- <u>发行方式</u>: 发行方只需要注册一次,就可以在持续时间内不断发行不同期限和收益率的债券,<u>相比传统债券成本更低且更灵活,融资速度也更快。</u>
- 反向征询: 投资者向发行方提出针对特定期限和收益率的债券发行请求,在当前的MTN发行总量中占了很大的比例,并且进一步提高了灵活性。
##### 5.7 优先股
- 分红率: 可以固定/基于标定利率浮动/以商业票据利率竞价,并且需要征税,但是税收相对较低,公司持有甚至可以免除70%的分红税,因此投资者几乎没有散户。
- 分红风险: 无法提供分红不会使公司破产,而是让渡权利。此时基于条款决定未实现分红是否需要累积。
- 沉没基金条款: 几乎所有优先股都有定期退役回购条款,可以通过现金或者支付普通股进行回购,此时会随机选择回购对象。
### 6. 另类债券
##### 6.1 浮动利率债券 (Floating Rates Bond)
- 发行方式: <u>政府和企业都会发行</u>,通常利率由基准利率和额外利差共同决定,半年重置一次,同时利率可能存在浮动上下限以控制发债人的风险。
- 基准利率: 通常是LIBOR或者联邦基金利率等短期利率,可能正相关也可能负相关,甚至可能有多个基准利率。
- 额外利差: 在基准利率之上投资者额外要求的收益,发行之后不会直接改变,债券价格的波动可以反应市场隐含利差。该利差可能有发行方信用,流动性,期权属性和市场状况共同决定。
- 影响价格因素: 1. 债券到期/充值时间,时间越长,债券波动率越大 2. 市场对额外利差的供需变化 3. 利率是否已经达到浮动上下限。Index duration描述对基准利率变动的敏感度,Spread duration则对应额外利差。
##### 6.2 Foreign Bonds
- 定义: 发行国家和发行市场不同的债券,和国内市场相关性低,收益率和风险都更高。
- Yankee Bond: 外国主权在SEC注册并在美国市场发行的债券,以美元计算利息。
- Eurodollar Bonds: 在美国境外发行,以美元计算利息的债券,不需要在SEC注册。发行者以公司为主,但也可以是其他机构,投资者以散户为主。
- 收益率计算: 需要同时考虑本币收益率和汇率风险,本币收益率较低的债券,可能因为通胀也较低而获得高真实收益率。
##### 6.3 Emerging Market Bonds
- 债务构成: 新兴国家的债务的大部分是国内债务,外债则以主权债务为主。并且由于外债监管少,交易更加活跃,流动性也强,并且评级从98年后不断上升,通过<u>IGOV指数</u>可以跟踪债务市场情况。
- Brady Bond: 银行债务违约国家通过发行债券的方式偿还贷款,但同时必须接受宏观方面的经济制度改革,历史证明<u>仅仅重组贷款不够,还必须减免债务。</u>
- 收益率: 新兴国家的债券收益率高,但是风险也高,夏普率约为0.6,低于美国企业债,但是优点是<u>相关性较低,流动性也较好。</u>
##### 6.4 Stable Value Investments (Guaranteed Investment Contract)
- 发行方式: 以保有账面本金为首要目标的保险合约,针对养老金等低风险机构投资者,流动性通常较差,但取决于被保对象。GIC可以对不同的证券提供保障,甚至可以直接管理整个投资组合,优点在于不用在SEC注册。
- Separate Account GIC: 资产和发行方用分开的账户管理,确保即使发行方倒闭合约价值也不会受到影响。
- Synthetic GIC (Wrapped Agreement): 投资者把资产存入作为保险对象的同时依然维持资产所有权并从原资产上获得收益,资产也可以是现金以外的其他证券,因此GIC的浮动价值也有久期等性质。
- Buy-and-Hold Synthetics: 合约提供对应资产的收益率,但是投资者必须持有合约到期,通常发行方是一个团体来共担风险。
### 7. 可转债
##### 7.1 可转债定义
- 转换价格/转换股数: 条款中规定了面值可以转换的股票数量或者股票价格,两者是对应的,但可能随着时间/拆股而改变。转换证券可以是发行方股权,等值债券,或者近似证券。
- 债务属性: 通常是<u>次级债券</u>,破产时索赔顺序在普通债券之后。利息率通常大于股票分红利率,但收益率比常规债券低。
- 股票期权属性: 当股票价值较高时,可转债和股票价格同涨同跌,但始终高于股权价值,同时还和股票的波动率正相关。
- 债券期权属性: 大部分可转债发行方提前赎回权利,但通常前几年有赎回保护,发行方会为了鼓励持有者转换或者希望再融资使用赎回权。投资人有时候也有赎回权,但收益率会更低。
##### 7.2 <u>转换分析</u> 
- 转换比: 为了等于可转债面值所需要的当前股票数量,数量越低越好。
- <u>转换平价 Conversion Parity</u>: 和可转债面值对应的股票价格,只有在股价超过转换溢价时才值得转换。
- 转换溢价 Conversion Premium: 当前股价距离转换平价的距离,转换溢价比反应所需要的涨幅。
- 价值溢价 Investment Premium: 可转债相对于债券价值的溢价,价值溢价比反应了溢价超出债券的比例。
- <u>breakeven time</u>: 定义为<u>转换溢价比/(债券收益率-分红率)</u>,反应了持有可转债的回本时间,越短越可转债越有吸引力。具有参考价值,但只能用来评估发行方类似的可转债。
##### 7.3 价值分析
- 投资人往往在<u>看多波动率的情况下才会交易可转债</u>,而发行人往往认为公司业绩会相对稳定。
- 可转债的价值通常由bond floor和股票的上行潜力共同决定,因此和其他资产相关性较低,可以提高夏普率。
- 可转债理解成持有债券和股票期权,也可以理解成同时持有股票,转换成债券的期权以及分红利息掉期,但估值时不可以直接将各个资产价值相加。
- 当股价较低时,bond floor和利率环境决定了可转债的价值,由于是次级债券,这时需要关注<u>信用风险</u>,可能要CDS对冲。
- 当股价较高时,可转债主要由股权决定,此时delta几乎等于1。但是由于债务价值托底,在股价较低时波动率通常小于常规股票。
##### 7.4 估值模型
- 影响估值的变量有: 股价,股价波动率,利率,违约率,分红率,税务影响,赎回概率,期限,流动性,汇率,基本面价值等。
- 因为变量太多,且PDE方程没有解析解,通常用有限微分法结合泰勒展开对PDE获得数值解。
- 通常定义股价和利率为服从log-normal和均值回归分布的随机变量,对未来价值进行模拟。
- 可以从当前市场期限结构,期权,CDS价格中得到未来利率,违约率,波动率的变化情况。
##### 7.5 可转债变种
- 常规可转债: 通常发行量在$50M以上,公开市场交易,具有3年的赎回保护期和5-10年的债券期限。有时候也会有面向私人市场的结构性产品。
- 无息可转债(LYON/OID/PIK): 发行价格低于面值,转换的股数不变,转换价格会逐渐上升。OID属于LYON和常规可转债的折中产品,PIK则只有初期没有利息,但性质都相同。
- <u>CoCo</u>: 只有当股价达到事先规定的要求时,投资人才有权利转换股票,有利于发行方,在美国很流行。
- 可转优先股: 以优先股形式发行,但是可以转换常规股票。优先股的赔偿顺序在可转债更后,但是赎回保护更好。
- 混合可转债: 以信托形式发行,在投资人方为优先股,但是在发行人方为债务,用于减少税务负担。
### 8. <u>信用衍生品</u>
##### 8.1 债券期货/远期合约
- <u>Conversion Ratio</u>: 所有远期合约按照债券以6%收益率折现后的价格定价,折现比例为转换率
- <u>交割选项</u>: 通常债券期货有一揽子交割选项,交割方会交割转换后价格最低的债券,这也提供了更多的套利机会,但价差不大。
- 远期合约是OTC交易的定制合约,通常会实物交割,需要警惕对手方风险,因此有抵押物要求。远期合约流动性较差,很难平仓,因此只能通过反向开仓来平仓。
- 债券期货是标准化合约,通常不会实物交割,但是有初始和可变保证金要求。如果不考虑交割期权的价值,则<u>期货,现货,利率,票息率存在关系</u>: $F=S e^{r-c}$。
- <u>期货术语</u>: <u>基差basis</u>=$S-F$,反应了期货和现货的关系,会在交割日收敛为0. Carry$=r-c$反应了利差,<u>如果提前交割必然会损失Carry</u>。
- 国债期货是最主流的期货产品,可以用来<u>控制投资的久期</u>,使得整体的DA01=0。
- 利率期货同时有对应期权,但是做空期权的持有者需要提供保证金确保在对手方行权的时候可以交割。
##### 8.2 <u>利率掉期互换</u>
- <u>利率互换定义</u>: 交易双方在未来一段时间交换基于notional的利率现金流,一方支付浮动利率,一方支付合约规定的固定利率,浮动利率在每个支付周期开始前确定。
- 交易方式: 买方支付固定利率,卖方支付浮动利率。通常在OTC交易,双方都用固定利率报价,对手方风险较高。
- 利率互换定价: 对未来不同方向的现金流折现后评估互换的价值,需要准确评估未来的利率曲线。
- 利率互换变种: notional可以随时间改变/两边都是不同的浮动利率/启动时间可变/启动后可修改浮动利率/超短期互换
- 利率互换期权: 因为利率互换风险主要在对手方,且进入互换后很难在OTC退出,因此投资人更青睐利率互换期权来获得相同的风险暴露。
##### 8.2 <u>利率期权</u>
- Cap/Floor: 当利率高/低于strike rate时,买家获得notional * abs(rate-strike)的现金流,可以提供非对称的风险保护。<u>同样基于利率曲线预测使用现金流折现定价</u>。
- Cap Floor Parity: <u>锚定于相同strike rate的floor和cap之和等效于对应的利率掉期互换</u>
- Straddle/Strangle策略: 同时持有做多和做空期权,并使$\delta=0$,本质是做多波动率。
- <u>Spread Trades/Corridor</u>策略: 同时做空和做多基于相同衍生品但不同行权值的同向Cap/Floor,使自己的风险暴露仅限于行权值之间。
- Covered Calls策略: 在持有标的的时候做空OTM的认多期权,通过牺牲上涨空间换取期权的出售价值。
- Compound option: 用于进入Cap/Floor的期权,类似利率互换期权,用来保护对手方风险并提高杠杆。
##### 8.5 <u>信用违约互换(CDS)</u>
- CDS定义: 买方向卖方交付以CDS spread为利率的保费,卖方在发生信用违约事件时被保证券的面值损失。实体交割需要买方提供违约债券交换面值,现金交割则卖方直接弥补差价。
- <u>CDS定价</u>: 需要场景分析债券违约的概率,再使用未来期望现金流的折现来评估现值并定价。违约风险越高,被保护的东西价值越高,CDS spread也越高。
- CDS调仓和交易: CDS互换通常以对手方风险为主,直接反向开仓会提高对手方风险,而取消和转售则要承担流动性成本。CDS转售时不会修改CDS spread,而是一次性付完差价。
- <u>CDS指数</u>: 北美使用CDX,欧洲使用iTraxx。如果CDX中的部分债券违约,则卖方赔偿后notional会降低,直到下次调仓。
- Basket Swap: 对一揽子证券进行违约保护的CDS,可以在$n$个成分都违约后再进行赔偿,价格取决于每个成分违约率的联合分布,$n$越低,spread越高。
- CDS Option: 包含4中期权,可以随时进入/退出CDS的两种方向,用于降低对手方风险,期权价值几乎完全取决于信用风险和波动率。
### 9. Mortage-Backed Securities
##### 9.1 Mortage Overview
- 借款人使用房子作为抵押获得购房贷款,如果违约房子就会被收回,通常贷款期限$T$为30年,每月支付房贷。如果拖欠超过90天,则被定义为违约。
- 房贷利率: 根据市场和投资人信用状况,$r$可以是固定的,或者在浮动利率LIBOR等指标上添加基差,可变利率房贷通常每年重设利率。
- 影响投资人信用的因素:
  
| Credit Scores      | Loan-to-Value (LTV)               | Income Ratio   | Documentation                     |
|--------------------|-----------------------------------|----------------|-----------------------------------|
| 借款人的FICO Score | 贷款价值/抵押品市值(越低风险越低) | 收入占月供比例 | 证明信用的文档 |

- 月供计算公式 $P=\text{Original\_Balance}\times\frac{r(1+r)^T}{(1+r)^T-1}$
- <u>预付风险</u>:通常,借款人可以随时提前还清贷款,这给放贷人和投资人带来了预付风险,<u>因此MBS凸性为负</u>。
  - Single Monthly Mortaility (SMM): 计算每个月贷款中被预付的资金比例 
  - Conditional Prepayment Rate (CPR): 计算每年贷款中被预付的比例,可以计算为$CPR=1-(1-SMM)^{12}$
  - <u>CPA模型</u>: SMM从0.2%开始,每个月上升0.2%,直到CPR达到6%后不变。CPR通常会在利率较低时升高,同时夏天也会更高,但在达到6%之后往往恢复稳定,因为剩下的借款人通常难以支付房贷。
##### 9.2 Agency MBS
- <u>发行方式</u>: 政府机构GSE从放贷人处购买房贷,并将相似的房贷打包成证券在市场上发售,信用程度甚至大于AAA债券。基于MBS的性质,本金和利息通常一起逐步偿还,而不是类似债券到期偿还。
- WAC/WAM: MBS背后的各个房贷基于市值加权后保留的利率/期限,可以描述MBS的整体情况。
- 市场传统: 交易员通常交易1个月后的远期MBS以便于对冲利率,同时使用360/30法计算利息,并用国债息差报价,最优的息差计算方式是基于现金流加权的。
##### 9.3 Collateralized Mortage Market
- 发行方式: 对MBS的现金流重组,基于支付期限和信用程度划分到不同的tranche,使得投资人可以更加灵活的配置风险和收益。
- CMO结构:
  - <u>Planned Amortized Class CMO (PAC)</u>: 基于预设的计划在不同的tranche中分配收入,并使用低等级tranche维护高级tranche收益的稳定性。
  - <u>Sequential tranche CMO</u>: 只有高等级的tranche被完全支付之后才会支付低级tranche,因此高级tranche的收益波动更大,同时低级tranche的收益会减少。
  - Targeted Amortization Class (TAC): 在PAC的基础上添加Call Protection,但是期权属性提高CMO在低预付率时的风险。
- CMO不同的tranche:
  - Z/Support Bond: 在CMO中作为最低的tranche吸收现金流波动,风险较大。Z Bond所有收益在CMO全部到期偿还,Support Bond则有分配计划。
  - Very Accurately Determined Maturity (VADM): 基于借款人实际偿还本金的时间来支付收益,风险更大。
  - Floater/Inverse Floater: 将CMO中固定收益的tranche基于浮动利率拆分,重组现金流使其对浮动利率有暴露。
  - Interset/Principle Only Tranches: 只支付贷款者利息/本金的tranche。IO tranche希望高利率,PO反之希望高预付,可以帮助投资者控制风险暴露。
- 信用评级: Agency CMO通常是AAA级,但是对于non-agency CMO,评级机构会参考底层MBS的资产类型,地理位置,贷款类型/规模/目的和发行放风险。通常non-agency CMO需要使用<u>信用增强</u>来CMO的信用。
  - External Enhancement: 通过第三方机构提供担保.
  - Internal Enhancement: 通过预设保留资金/次级tranche来吸纳风险。
##### 9.4 Subprime ABS
- 发行方式: 同样是房贷,但是贷款来自于信贷记录不良的借款人,和其他MBS相关性低,且凸性更好。
- 预付率: 预付率高,且上升速度快,因为借款人想要尽快提高自己的信用水平,因此预付率受利率影响低。
- 信用增强: Subprime ABS采用PAC和Sequential CMO结合的方式,在前3年只有高级tranche可以获得本金收入,随后次级tranche才解禁,同时发行方还会进行拖欠和违约测试确保高级债券可靠性。
##### 9.5 Commerical Mortage Backed Securities (CMBS)
- 发行方式: 基于商业地产/酒店/厂房等设施发行的房贷,通常有10年的预付保护,因此主要风险在于违约。与传统MBS不同,<u>CMBS的大部分本金往往在到期日返还,借款人同时需要提供大量文件证明一次性还款能力。</u>
- 信用增强: 通常一个CMBS包含不同地域,不同房产类别的房贷来降低风险,分散性指标必须大于压力测试阈值。
- 风险特点: 通常必须在10年后才可以预付
### 10. Other Asset Backed Securities
##### 10.1 Credit Card ABS
- 发行方式: 将信用卡债务基于Basic Master Trust Structure打包到收益池,再发行不同的tranches结合信用增强来满足不同的投资/评级需求。
- 信用卡ABS市场:是流动性最强,规模最大的ABS产业,并且市场处于寡头垄断状态。在常规信用卡之外,还有商业公司开发特殊优惠的信用卡,或者只有特定场景可以使用的信用卡。
- Revolving Period: 投资人在循环期只能获得信用卡的利息收益,因为此时本金收益被用作下一轮贷款。
- Amortization Period: 改时段内,投资人会逐步获得信用卡借款的本金收益。如果遇到信用事件,则会提前开启分摊期。
- 收益分配: 投资者收益是预先固定的收益率,剩余的收益属于发行者,并用来吸收投资波动。信用卡收益会先根据投资者/发行者打包,随后在循环期偿还利息,最后在分摊期完全返还收益。不同层级间,可以根据层级收益需求或预先设定的比例分配收益。
##### 10.2 Automobile Lease Backed Securities
- 发行方式: 购车者找到dealer购车,dealer负责帮助购车人找到银行申请车贷。可靠的dealer申请贷款的历史成功率也高。
- Absolute Prepayment Rate: 计算年化的被预付的车贷数量,预付率通常取决于消费者行为和经济周期。
- 车贷几乎不会受到利率影响,因为借贷者不会再融资购车。
- 信用风险: 放贷人会根据贷款人的信用分发行贷款,如果债务拖欠并违约,车辆将会被前行拍卖。
- 低LTV: 由于车辆贬值较快,放贷人不会提供等于车辆当前价值的贷款,贷款人必须自己出资一部分。
##### 10.3 <u>CDO</u>
- 发行方式: 将<u>不同类型的ABS资产</u>打包池化,再分成不同tranches出售。tranch的利率是浮动的,但是ABS往往固定,因此中间需要Rate Swap.
- Balance sheet/Cash Flow CDO: 转移资产风险和固定收益,同时赚取手续费。Cash Flow CDO需要定期进行测试来计算在每一层tranche计算对上层的保护程度,只有超过一定阈值,才可以将收益发放给该tranch
  - Coverage Test: $\text{O/C Ratio}=\frac{\text{Total Par Value}}{\text{Current Tranche Par Value}+\text{All Above Tranche Par Value}}$
  - Interest Rate Test:和Coverage Test类似,只不过使用利率而不是Par作为测试参数。
  - Quality Test: 确保CDO的分散度,加权评级/期限/息差/利率都符合标准。
- Arbitrage CDO:通过出售CDO来赚取价差,manager会想办法提高CDO的市值,同时降低波动率。
- Cash CDO投资原则:
    1. 关注CDO manager的历史表现和激励机制 
    2. 选择合适的底层ABS类别 
    3. 考虑整个投资组合中所有CDO在一起后的分散度。
    4. 关注预付概率高的CDO,可以显著提升收益。
##### 10.4 <u>Synthetic CDO</u>
- 发行方式: 使用<u>CDS等衍生品作为抵押物打包池化。</u>因为投资者可以任意选择CDS,因此不需要manager,同时管理费用低,没有利率和融资成本。
- Unfunded SCDO: 投资者为底层underlying提供保险,获得保费。如果信贷实践发生,则投资者需要提供担保支持,因此投资者需要有良好信用记录。
- Funded SCDO(Credit-Linked Notes):投资者需要使用SPV购买抵押物来确保自己可以提供担保
- ISDA:条款明确规定了信用事件的定义,同时设立了保证金和交割的标准化原则。
- 投资原则: 关注CDO底层资产的违约相关率,确保不会同时违约造成大规模赔付,同时要尽量进行delta对冲。
- <u>SCDO定价:</u>先基于衍生品的相关性和赔付数量对Basket Swap定价,随后再基于attachment point对不同tranch定价。从SCDO的价格中可以反向推导出相关性。
### 11. Credit Analysis:
##### 11.1 Financial Analaysis:
- 根据产业周期,公司财报,信用评级,杠杆率, ROE, Pretax interest coverage, EBITDA coverage和各项因素分析公司的违约概率,<u>通常要和同行业对比</u>。
- 非财政因素: 监管,上游资源,成长空间和护城河,资本结构,国际贸易影响,行业竞争位置。
- 财政因素: 杠杆率,固定和浮动收入,现金流支出,资产质量,分散程度,会计质量,债券安全性,资产流动性,经营杠杆率,营收规模。
- High Yield: 适合用股票方法研究,分析杠杆,经营,护城河等因素,并常用MDA预测违约概率,<u>寻找因为评级滞后性导致的套利机会</u>。
##### 11.2 <u>Incomplete-Information Credit Models $(I^2)$</u>
1. 相对而言,该模型可以最精准地反应公司的现实,并且假定在时间周期内,只要公司的资产$A$小于D,即违约。
2. 对公司间的$D$的covariance进行建模,并根据市场情况,实时更新当前$D$的分布,这样可以及时反映市场的突然变化。
3. 假定公司价值$V$服从lognormal distribution,从股价和期权中可以反向得到波动率和asset value.
4. 波动率或蒙特卡洛法对公司的资产$A$进行模拟,再减去$D$获得违约的概率。
##### 11.3 Municipal Obligation and Revenue Bond
- 分析债券的收入来源,索取收入的优先级,必须确保项目收入的增长比债务快。
- 找清楚谁是真正的发行方以及开展项目的能力。
##### 11.4 Rating Agency Approach
- 抵押物分析: 主要考虑在违约情况下的回收率。
- 现金流收入模型: 考虑次级债券结构,储备基金,超额抵押,额外利差是否可以为利息提供缓冲。
- 对手方分析: 分析债券中的利息和违约条款,服务方转移现金流的能力,和抵押物资产的管理追评。
### 11. Bond Portfolio Management
##### 11.1 Benchmark Selection
- 指数的优势: 流动性好,管理成本低,通常指数的涵盖范围越广越好。
- 指数的主要风险因子:久期,现金流分布,期限,评级,产业和预付敞口。
- 设定Benchmark: 指数的成分必须是可以在市场中交易的,在低利率下短期限的投资组合风险更低,更受欢迎。
##### 11.2 Benchmark Tracing
- 衡量benchmark和tracking的标准: 收益率,相对指数的beta,information ratio, PnL attribution。有的benchmark期限很长,没有短期mark-to-market比较的价值,这时比较cum PnL。
- Scenario analysis: 用理论情景模拟当前的portfolio表现,并和benchmark的表现进行对比,进行stress test。
- Primary Risk Match: 在投资组合的每个期限分布的子portfolio中,还要尽量保证其他风险因子匹配。
##### 11.3 Enhancement Strategy
- Minor Mismatch: PM在每个风险因子上有20-40bps的偏差,并通过主动操作来提高收益并降低portfolio中成分的相关性。
- Reduce Issuer Exposure: 控制住对于每个issuer的风险,如果某个issuer占比过高,可以降低对其仓位并分给其他issuer,但这样可能会影响追踪精确度。通过issuer权重乘以波动率可以估计风险。
- Credit Enhancements: 通过watch list等数据观察评级的趋势,并提前做多/做空将要升/降级的资产,在HY/IG划分点机会最多
- Yield Credit Enhancements: 通过对收益率变化的预测调整仓位,通常做多长债的利率,做多短债的利率。
- Sector Enhancements: 把中短期国债换成企业债通常可以提高收益,因为不同企业债之间的低相关性可以降低非系统性风险,同时公司债券的duration也会降低。
- Derivative Enhancements: CDS可以更精准地衡量企业的信用风险,因此使用TBD/CDS来低成本地控制信用风险的暴露。
- Volatility Enhancements: 在市场剧烈波动的时候,流动性会下降,并且带有期权的债券价值会上升,特别是带有put option的债券,通常被低估。
##### 11.4 Cash-flow Matched Portfolio
- 应用: 通常应用于管理养老金等有稳定支出需求的投资组合,通过衡量收益和支出的匹配程度来评估质量。支出计划在确定后不能有大改动。
- 选定投资组合: 通常需要考虑再投资利率,可投资范围(尽量减少期权和预付款暴露),随后再选取最合适的资产
- 再优化: 通常投资组合是被动管理的,只有当市场有更优选择的时候重新优化,降低组合的投资成本。
- Income Risk: 当投资组合的本金来源于外部现金流时,长久期的投资组合可以降低外部现金流波动对投资组合收益的影响。
- Libaility Risk: 当投资组合需要用收益偿还负债时,<u>需要尽量匹配两者的现金流</u>,这样可以缓解利率曲线不平行移动的风险和再投资的不确定性。
##### 11.5 International Management
- 市场选择: 要考虑国家,外汇,通胀,税务,流动性,评级以及可选的benchmark。通常EM市场的潜在收益最大。
- 外汇对冲: 通常对冲50%的外汇风险可以最大化收益风险比。当外汇对冲成本很高的时候,可以选取成本较低,相似度较高的货币代替。
- PnL attribution: 资产相对于当地指数的超额收益($\alpha$),指数相对于当地货币的收益($\beta$),货币之间的外汇变化。
##### 11.6 Transitional Management
- 调整投资组合,更新策略和管理方式的过程,包括设定计划,实施交易和总结汇报。调整人通常被作为交易操作而不是法人。
- 交易计划: 包括交易和流动性成本分析,fair value价值评估和交易时间计划表。
- 实施交易: 需要控制交易过程对于市场波动的风险和信息风险,基于fair value以及流动性评估按照不同节奏进行交易。
- 总结汇报: 分析转换完成后的投资组合,计算交易成本,清算未完成的交易并分析原因。