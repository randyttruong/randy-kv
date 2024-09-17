/*
 * node_discovery.types.ts
 *
 * This file contains the types for the node discovery service.
 * It contains the types for the Node and the NodeStore, as well
 * as the request and response types for the various endpoints.
 *
 * Note: These types are shared between the server and the client.
 * Additionally, these types are consistent with the proto file.
 */

export enum AgentStatus {
    UNKNOWN = 'unknown',
    HEALTHY = 'healthy',
    UNHEALTHY = 'unhealthy',
    OFFLINE = 'offline',
}


export class Agent {
    constructor(
        private id: string,
        private address: string,
        private port: number,
        private status: AgentStatus,
        private lastHeartbeat?: string) {};

    public setID(id: string): void { this.id = id; }
    public getID(): string { return this.id; }

    public setAddress(address: string): void { this.address = address; }
    public getAddress(): string { return this.address; }

    public setPort(port: number): void { this.port = port; }
    public getPort(): number { return this.port; }

    public setStatus(status: AgentStatus): void { this.status = status; }
    public getStatus(): AgentStatus { return this.status; }

    public setLastHeartbeat(lastHeartbeat: string): void { this.lastHeartbeat = lastHeartbeat; }
    public getLastHeartbeat(): string { return this.lastHeartbeat; }
}

export interface AgentStore {
    [id: string]: Agent;
}

// `/register` - RegisterAgent
export interface RegisterAgentRequest {
    id: string;
    address: string;
    port: number;
}

export interface RegisterAgentResponse {
    success: boolean;
    message: string;
}

// `/deregister/` - DeregisterAgent
export interface DeregisterAgentRequest {
    id: string;
}
export interface DeregisterAgentResponse {
    success: boolean;
    message: string;
}

// `/heartbeat/` - Heartbeat
export interface HeartbeatRequest {
    id: string;
}
export interface HeartbeatResponse {
    success: boolean;
    message: string;
}

// `/nodes/` - GetAgents
export interface GetAgentsRequest {}
export interface GetAgentsResponse {
    success: boolean;
    message: string;
    nodes?: AgentStore;
}

// `/peers/` - GetPeers
export interface GetPeersRequest {
    id: string;
}

export interface GetPeersResponse {
    success: boolean;
    message: string;
    peers?: AgentStore;
}


// `/nodes/status/` - GetAgentStatus
export interface GetAgentStatusRequest {
    id: string;
}
export interface GetAgentStatusResponse {
    success: boolean,
    message: string;
    status: AgentStatus;
}


// `/update-metadata/` - UpdateAgentMetadata
export interface UpdateAgentMetadataRequest {
    id: string;
    address?: string;
    port?: number;
}
export interface UpdateAgentMetadataResponse {
    success: boolean;
    message: string;
}