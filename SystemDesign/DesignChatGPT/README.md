# System Design Interview: Design ChatGPT
When building an AI chat system, many assume it’s as simple as calling an API and storing chats in a database. This approach works at small scale, 
but at ChatGPT’s scale — billions of visits and prompts each day — it quickly breaks down. Storing all those messages would require hundreds of 
terabytes per year, far beyond what a normal database can handle. Meanwhile, API costs would reach hundreds of millions per month, which is not 
sustainable. Handling millions of users chatting simultaneously also demands infrastructure far beyond a single server.

Why this matters:
- Each user maintains a persistent connection to the server, and managing millions of stateful connections is a major engineering challenge.
- Senior engineers must design systems that control infrastructure costs while keeping the app fast, stable, and responsive.
- They also need to handle failures gracefully when parts of the system inevitably go down.
- Ultimately, the goal is to design architectures that can scale to billions of users without collapsing under the weight of traffic, storage, or cost.

## Clarifying Requirements
In system design interviews, skipping this step is an immediate red flag. Strong candidates always start by asking the right questions:

- Are we building the AI model itself, or integrating with an existing one?
- Do we need streaming responses (word‑by‑word) or complete responses?
- What’s the expected scale — thousands or millions of users?
- Do users need accounts and conversation history?
- Are conversations private or shareable?
- Do we support multiple languages?
- How do we handle rate limiting — free vs. paid tiers?
- Is it text only, or do we also support images and files?
- Do we need content moderation?

## Assumptions for This Design
- Integrating with an existing LLM (not building the model ourselves)
- Streaming responses required for good UX
- As of Feburary 2026: 800–900M weekly active users, 2.5B+ prompts per day
- Users need accounts, with private conversations and history
- Text only, English first
- Rate limiting on both requests and tokens

